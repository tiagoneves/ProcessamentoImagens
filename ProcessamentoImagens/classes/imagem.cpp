
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

void Imagem::crop(double cx, double cy, int width, int height){

    Rect rect(cx, cy, width, height);

    Point2f centro(cx, cy);

    if (rect.contains(centro)) {

        getRectSubPix(matriz, Size(width, height), centro, matProc);

        salvar();

    } else

        throw NotSupportedOperationException("O centro do retângulo não está na imagem");

}

void Imagem::rotacionar(double cx, double cy, double angulo){

    Mat matRot = getRotationMatrix2D(Point2f(cx, cy), angulo, 1);

    transform(matriz, matProc, matRot);

    salvar();

}

void Imagem::salvar() {

    imwrite(local, matProc);

}

const char* Imagem::getLocal() {

    return local;

}
