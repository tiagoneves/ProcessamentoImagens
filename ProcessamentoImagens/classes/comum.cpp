
#include "../include/comum.h"
#include <time.h>

Comum::Comum(Imagem *img){

	imagem = img;	

}

int Comum::operar(char **argv)
{

    clock_t start;
	
    try {

	char* operacao = argv[1];
	const char* diretorioSaida;

        if (strcmp(operacao, "redimensionar") == 0){
	    
	    diretorioSaida = argv[5];

            double x = atof(argv[3]);
            double y = atof(argv[4]);

	    start = clock();

            imagem -> redimensionar(x, y);

        } else if (strcmp(operacao, "converter") == 0){
            
            diretorioSaida = argv[4];
	
	    const char* localSaida = imagem -> obterLocalSaida(diretorioSaida, 
			trocarExtensao(imagem -> getLocal(), argv[3]));
	
            start = clock();

            imagem -> converter(localSaida);
             
	    exibirTempoExecucao(start);
            

        } else if (strcmp(operacao, "cortar") == 0) {

	    diretorioSaida = argv[7];

            double xUp = atof(argv[3]);
            double yUp = atof(argv[4]);

            double xLow = atof(argv[5]);
            double yLow = atof(argv[6]);

            start = clock();

            imagem -> crop(xUp, yUp, xLow, yLow);

        } else if (strcmp(operacao, "rotacionar") == 0) {
            
            diretorioSaida = argv[4];

            double angulo = atof(argv[3]);

            start = clock();

            imagem -> rotacionar(angulo);

        } else if (strcmp(operacao, "equalizar") == 0) {

	    diretorioSaida = argv[3];

	    start = clock();
            
            imagem -> equalizarHistograma();		
		
        } else if (strcmp(operacao, "convolução") == 0) {

	    int linhas = atoi(argv[3]);

	    int colunas = atoi(argv[4]);

	    diretorioSaida = argv[5 + linhas * colunas];
	    
            double **mascara;

            int i, j, indiceEntrada = 5;

            mascara = (double**) malloc(linhas*sizeof(double*));
  
            for (int i = 0; i < linhas; i++)
  
               mascara[i] = (double*) malloc(colunas*sizeof(double));  
    
	    for (i = 0; i < linhas; i++) {

	       for(j = 0; j < colunas; j++)

		  mascara[i][j] = atof(argv[indiceEntrada++]);

             }

            start = clock();

	    imagem -> convolucao(linhas, colunas, mascara);
		
        } else if (strcmp(operacao, "dct") == 0) {

	    diretorioSaida = argv[3];
            
            start = clock();
            
            imagem -> dct();

        }

	if (strcmp(operacao, "converter") != 0) {

		const char* localSaida = imagem -> obterLocalSaida(diretorioSaida, imagem -> getLocal()); 
  
		imagem -> salvar(localSaida);

		exibirTempoExecucao(start);
		
        }

    }catch(FileNotFoundException fnf) {

        //printf("%s", fnf.obterMensagem());

	return 0;

    }catch(NotSupportedOperationException nso) {

        //printf("%s", nso.obterMensagem());

	return 0;

    }

    return 1;
}

void Comum::exibirTempoExecucao(clock_t start) {

	clock_t end;
	
	double tempo;

	end = clock();
		
        tempo = (end - start) * 1000 / CLOCKS_PER_SEC;

        printf ("O tempo de execucao da operacao foi de %f milissegundos.\n", tempo );

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

