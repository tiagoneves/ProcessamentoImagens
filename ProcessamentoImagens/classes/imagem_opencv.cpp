
#include "../include/imagem_opencv.h"
#include "../include/excecoes.h"

Mat matriz, matProc;

ImagemOpenCV::ImagemOpenCV(const char* caminhoEntrada)  : Imagem (caminhoEntrada){

    matriz = imread(caminhoEntrada, 1);

    if (matriz.data != NULL){

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

void ImagemOpenCV::crop(double xUp, double yUp, double xLow, double yLow)const{

    double width = xLow - xUp;
    double height = yUp - yLow;
    double cx = xUp + width / 2;
    double cy = xLow + height / 2;

    Rect rect(cx, cy, width, height);

    Point2f centro(cx, cy);

    if (rect.contains(centro)) {

        getRectSubPix(matriz, Size(width, height), centro, matProc);

    } else

        throw NotSupportedOperationException("O centro do retângulo não está na imagem");

}

void ImagemOpenCV::rotacionar(double angulo) const{

    Point2f centro(matriz.cols/2.0F, matriz.rows/2.0F);

    Mat matRot = getRotationMatrix2D(centro, angulo, 1.0);

    warpAffine(matriz, matProc, matRot, matriz.size());


}

void ImagemOpenCV::equalizarHistograma() const {

	cvtColor(matriz, matriz, CV_BGR2GRAY);

	equalizeHist(matriz, matProc);

}

void ImagemOpenCV::salvar(const char* localSaida) const {

    imwrite(localSaida, matProc);

}
