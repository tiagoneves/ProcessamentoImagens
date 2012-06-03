
#include "../include/comum.h"

Comum::Comum(Imagem *img){

	imagem = img;	

}

int Comum::operar(char **argv)
{

    try {

	char* operacao = argv[1];
	const char* diretorioSaida;

        if (strcmp(operacao, "redimensionar") == 0){
	    
	    diretorioSaida = argv[5];

            int x = atoi(argv[3]);
            int y = atoi(argv[4]);

            imagem -> redimensionar(x, y);

        } else if (strcmp(operacao, "converter") == 0){
            
            diretorioSaida = argv[4];

            imagem -> converter(trocarExtensao(imagem -> getLocal(), argv[4]));

        } else if (strcmp(operacao, "cortar") == 0) {

	    diretorioSaida = argv[7];

            double cx = atof(argv[3]);
            double cy = atof(argv[4]);

            int width = atoi(argv[5]);
            int height = atoi(argv[6]);

            imagem -> crop(cx, cy, width, height);

        } else if (strcmp(operacao, "rotacionar") == 0) {
            
            diretorioSaida = argv[6];

            double cx = atof(argv[3]);
            double cy = atof(argv[4]);
            double angulo = atof(argv[5]);

            imagem -> rotacionar(cx, cy, angulo);

        }

	const char* localSaida = imagem -> obterLocalSaida(diretorioSaida);   

	imagem -> salvar(localSaida);

    }catch(FileNotFoundException fnf) {

        printf("%s", fnf.obterMensagem());

    }catch(NotSupportedOperationException nso) {

        printf("%s", nso.obterMensagem());

    }

    return 0;
}

const char* Comum::trocarExtensao(const char* local, const char* extensao) {

    char* localRef = (char*)local;

    char* pontoRef = strrchr(localRef, '.');

    //strncpy(localSemExtensao, local, pontoRef - local);

    string localSemExtensao = copiarNPrimeirosCaracteres(local, pontoRef - local);

    //strcat(localSemExtensao, strcat(ponto, extensao));

    string localComExtensao = adicionarExtensao(localSemExtensao, extensao);

    return localComExtensao.data();

}

string Comum::copiarNPrimeirosCaracteres(const char* src, int qtd) {

    int i;

    string dest("");

    for (i = 0; i < qtd; i++)

        dest += src[i];

    return dest;

}

string Comum::adicionarExtensao(string src, const char* ext) {

    int tamSrc = src.length();

    int tamExt = strlen(ext);

    string dest ("");

    int i;

    for (i = 0; i < tamSrc ; i++) {

        dest += src.at(i);

    }

    dest += ".";

    for (i = 0; i < tamExt ; i++) {

        dest += ext[i];

    }

    return dest;

}

