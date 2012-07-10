
#include "../include/imagem_opencv.h"
#include "../include/excecoes.h"

Mat matriz, matProc;
IplImage* img;

ImagemOpenCV::ImagemOpenCV(const char* caminhoEntrada)  : Imagem (caminhoEntrada){

    matriz = imread(caminhoEntrada, 1);

    if (matriz.data != NULL){

        width = matriz.cols;

        height = matriz.rows;

    } else

        throw FileNotFoundException();

}

void ImagemOpenCV::redimensionar(double width, double height) const{

    resize(matriz, matProc, Size(width,  height));

}

void ImagemOpenCV::converter(const char* output) const {

    imwrite(output, matriz);

}

void ImagemOpenCV::crop(double xUp, double yUp, double xLow, double yLow) const { 

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

void ImagemOpenCV::rotacionar(double angulo) const {

    Point2f centro(matriz.cols/2.0F, matriz.rows/2.0F);

    Mat matRot = getRotationMatrix2D(centro, angulo, 1.0);

    warpAffine(matriz, matProc, matRot, matriz.size());


}

void ImagemOpenCV::equalizarHistograma() const {

        cvtColor(matriz, matriz, CV_BGR2YUV);

        vector<Mat> matriz_yuv;

        split(matriz, matriz_yuv);

	equalizeHist(matriz_yuv.at(0), matriz_yuv.at(0));

	merge(matriz_yuv, matProc);

	cvtColor(matProc, matProc, CV_YUV2BGR);

}

void ImagemOpenCV::convolucao(int linhas, int colunas, double** mask) const {
         
        Mat mascara = Mat(linhas, colunas, CV_32F);
	
	int i, j;

	for(i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++)
			mascara.at<double> (i, j) = mask[i][j];
        }   


	filter2D(matriz, matProc, -1, mascara, Point(-1, -1));

}

void ImagemOpenCV::dct() const {

        cvtColor(matriz, matriz, CV_BGR2GRAY);

	matriz.convertTo(matriz, CV_32FC1);

	cv::dct(matriz, matProc);

}

void ImagemOpenCV::salvar(const char* localSaida) const {

    imwrite(localSaida, matProc);

}
