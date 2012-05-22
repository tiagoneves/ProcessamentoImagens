#include <iostream>

#include "include/imagem.h"
#include "include/excecoes.h"
#include <string.h>
//#include "include/gui/frame.h"

using namespace std;

const char* trocarExtensao(char* local, char* extensao) ;

int main(int argc, char **argv)
{

    try {

        puts("Hello World");

        const char* img = argv[2];

        Imagem imagem(img);

        if (strcmp(argv[1], "redimensionar") == 0){

            int x = atoi(argv[3]);
            int y = atoi(argv[4]);

            imagem.redimensionar(x, y);

        } else if (strcmp(argv[1], "converter") == 0){

            const char* local = imagem.getLocal();

            const char* frmtConst = argv[3];

            imagem.converter(trocarExtensao((char*)local, (char*)frmtConst));


        }

        //MyFrame1 frame(NULL);

    }catch(FileNotFoundException fnf) {

        printf("%s", fnf.obterMensagem());

    }

    return 0;
}

const char* trocarExtensao(char* local, char* extensao) {

    char* pontoRef = strrchr(local, '.');

    char* localSemExtensao;

    strncat(localSemExtensao, local, pontoRef - local);

    char ponto[] = ".";

    strcat(localSemExtensao, strcat(ponto, extensao));

    return &localSemExtensao[0];

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
