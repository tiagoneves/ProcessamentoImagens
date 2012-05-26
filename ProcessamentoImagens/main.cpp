#include <iostream>

#include "include/imagem_opencv.h"
#include "include/excecoes.h"
#include <string.h>
//#include "include/gui/frame.h"

using namespace std;

const char* trocarExtensao(const char* local, const char* extensao) ;
string copiarNPrimeirosCaracteres(const char* src, int qtd) ;
string adicionarExtensao(string src, const char* ext);

int main(int argc, char **argv)
{

    try {

        /*argv[1] = "redimensionar";
        argv[2] = "imagens/Tulips.jpg";
        argv[3] = "200";
        argv[4] = "50";*/

        /*argv[1] = "opencv";
        argv[2] = "converter";
        argv[3] = "imagens/Penguins.jpg";
        argv[4] = "png";*/

        Imagem *imagem;

        const char* api = argv[1];
        const char* img = argv[3];

        //ImagemOpenCV imagem(img);

        if (strcmp(api, "opencv") == 0)
           imagem = new ImagemOpenCV(img);


        if (strcmp(argv[2], "redimensionar") == 0){

            int x = atoi(argv[4]);
            int y = atoi(argv[5]);

            imagem -> redimensionar(x, y);

        } else if (strcmp(argv[2], "converter") == 0){

            imagem -> converter(trocarExtensao(imagem -> getLocal(), argv[4]));

        } else if (strcmp(argv[2], "cortar") == 0) {

            double cx = atof(argv[4]);
            double cy = atof(argv[5]);

            int width = atoi(argv[6]);
            int height = atoi(argv[7]);

            imagem -> crop(cx, cy, width, height);

        } else if (strcmp(argv[2], "rotacionar") == 0) {

            double cx = atof(argv[4]);
            double cy = atof(argv[5]);
            double angulo = atof(argv[6]);

            imagem -> rotacionar(cx, cy, angulo);

        }

        //MyFrame1 frame(NULL);

    }catch(FileNotFoundException fnf) {

        printf("%s", fnf.obterMensagem());

    }catch(NotSupportedOperationException nso) {

        printf("%s", nso.obterMensagem());

    }

    return 0;
}

const char* trocarExtensao(const char* local, const char* extensao) {

    char* localRef = (char*)local;

    char* pontoRef = strrchr(localRef, '.');

    //strncpy(localSemExtensao, local, pontoRef - local);

    string localSemExtensao = copiarNPrimeirosCaracteres(local, pontoRef - local);

    //strcat(localSemExtensao, strcat(ponto, extensao));

    string localComExtensao = adicionarExtensao(localSemExtensao, extensao);

    return localComExtensao.data();

}

string copiarNPrimeirosCaracteres(const char* src, int qtd) {

    int i;

    string dest("");

    for (i = 0; i < qtd; i++)

        dest += src[i];

    return dest;

}

string adicionarExtensao(string src, const char* ext) {

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

/*#include <iostream>

using namespace std;

#include "cv.h"
#include "highgui.h"

int main(int argc, char **argv)
{
    IplImage *pImg;

    if (argc == 1) {

        if (pImg = cvLoadImage("Penguins.jpg", 1)) {

            cvNamedWindow("Image", 1);
            cvShowImage("Image", pImg);

            cvWaitKey(0);

            cvDestroyWindow("Image");
            cvReleaseImage(&pImg);

            return 0;

        }

        return -1;

    }

    return -1;

}*/
