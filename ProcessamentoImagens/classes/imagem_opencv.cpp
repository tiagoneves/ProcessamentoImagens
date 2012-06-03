
#include "cv.h"
#include "highgui.h"
#include "../include/imagem_opencv.h"
#include "../include/excecoes.h"

Mat matProc;

ImagemOpenCV::ImagemOpenCV(const char* caminhoEntrada)  : Imagem (caminhoEntrada){

    if (pImg = cvLoadImage(caminhoEntrada, 1)){

        matriz = (pImg);

        width = matriz.cols;

        height = matriz.rows;

    } else

        throw FileNotFoundException();

}

void ImagemOpenCV::redimensionar(double width, double height) const{

    //double x = nWidth - width;
    //double y = nHeight - heigh;

    //double novaLargura = width * fatorX;
    //double novaAltura = width * fatorY;

    resize(matriz, matProc, Size(width,  height));

}

void ImagemOpenCV::converter(const string output) const{

    matriz.copyTo(matProc);

    imwrite(output, matProc);

}

void ImagemOpenCV::crop(double cx, double cy, int width, int height)const{

    Rect rect(cx, cy, width, height);

    Point2f centro(cx, cy);

    if (rect.contains(centro)) {

        getRectSubPix(matriz, Size(width, height), centro, matProc);

    } else

        throw NotSupportedOperationException("O centro do retângulo não está na imagem");

}

void ImagemOpenCV::rotacionar(double cx, double cy, double angulo) const{

    Mat matRot = getRotationMatrix2D(Point2f(cx, cy), angulo, 1);

    matriz.assignTo(matRot, 16);
    //matriz.assignTo(matProc, 16);

    /*printf("%d\n", matRot.channels());
    printf("%d\n", matRot.type());
    printf("%d\n", matriz.channels());
    printf("%d\n", matriz.type());
    printf("%d\n", matProc.channels());
    printf("%d\n", matProc.type());*/

    //matriz.copyTo(matProc);

    matProc = matriz.mul(matRot);

    //imwrite(local, matRot);

    //transform(matriz, matProc, matRot);


}

void ImagemOpenCV::salvar(const char* localSaida) const {

    imwrite(localSaida, matProc);

}
