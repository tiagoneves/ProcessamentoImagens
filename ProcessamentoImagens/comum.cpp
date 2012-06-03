
Comum::Comum(Imagem *img){

	imagem = img;	

}

Comum::int operar(char **argv)
{

    try {

	char* operacao = argv[1];	

        if (strcmp(operacao, "redimensionar") == 0){
	    
	    imagem -> setLocalSaida(argv[5]);

            int x = atoi(argv[3]);
            int y = atoi(argv[4]);

            imagem -> redimensionar(x, y);

        } else if (strcmp(operacao, "converter") == 0){
            
            imagem -> setLocalSaida(argv[4]);

            imagem -> converter(trocarExtensao(imagem -> getLocal(), argv[4]));

        } else if (strcmp(operacao, "cortar") == 0) {

	    imagem -> setLocalSaida(argv[7]);

            double cx = atof(argv[3]);
            double cy = atof(argv[4]);

            int width = atoi(argv[5]);
            int height = atoi(argv[6]);

            imagem -> crop(cx, cy, width, height);

        } else if (strcmp(operacao, "rotacionar") == 0) {
            
            imagem -> setLocalSaida(argv[6]);

            double cx = atof(argv[3]);
            double cy = atof(argv[4]);
            double angulo = atof(argv[5]);

            imagem -> rotacionar(cx, cy, angulo);

        }

    }catch(FileNotFoundException fnf) {

        printf("%s", fnf.obterMensagem());

    }catch(NotSupportedOperationException nso) {

        printf("%s", nso.obterMensagem());

    }

    return 0;
}

Comum::const char* trocarExtensao(const char* local, const char* extensao) {

    char* localRef = (char*)local;

    char* pontoRef = strrchr(localRef, '.');

    //strncpy(localSemExtensao, local, pontoRef - local);

    string localSemExtensao = copiarNPrimeirosCaracteres(local, pontoRef - local);

    //strcat(localSemExtensao, strcat(ponto, extensao));

    string localComExtensao = adicionarExtensao(localSemExtensao, extensao);

    return localComExtensao.data();

}

Comum::string copiarNPrimeirosCaracteres(const char* src, int qtd) {

    int i;

    string dest("");

    for (i = 0; i < qtd; i++)

        dest += src[i];

    return dest;

}

Comum::string adicionarExtensao(string src, const char* ext) {

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

