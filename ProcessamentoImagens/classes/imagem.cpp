
#include "cv.h"
#include "highgui.h"
#include "../include/imagem.h"
#include "../include/excecoes.h"

Imagem::Imagem(const char* caminho) {

    if (pImg = cvLoadImage(caminho, 1)){

        local = caminho;

        matriz = (pImg);

        width = matriz.cols;

        height = matriz.rows;

    } else

        throw FileNotFoundException();

}

void Imagem::redimensionar(int x, int y){

    //double x = nWidth - width;
    //double y = nHeight - heigh;

    resize(matriz, matProc, Size(x, y));

    salvar();

}

void Imagem::converter(const string output) {

    matriz.copyTo(matProc);

    imwrite(output, matProc);

}

void Imagem::salvar() {

    imwrite(local, matProc);

}

const char* Imagem::getLocal() {

    return local;

}
