
#include "../include/imagem_cimg.h"
#include "../include/excecoes.h"

CImg<double> imagem;

ImagemCImg::ImagemCImg(const char* caminhoEntrada)  : Imagem (caminhoEntrada){
    
    try {

    	CImg<double> img(caminhoEntrada);

    	imagem = img;

    } catch(CImgIOException cie) {

       throw FileNotFoundException();

    }

}

void ImagemCImg::redimensionar(double width, double height) const{

    int widthI = (int) width;
    int heightI = (int) height;

    imagem.resize(54, 36);

}

void ImagemCImg::converter(const string output) const{

   //TODO

}

void ImagemCImg::crop(double xUp, double yUp, double xLow, double yLow)const{

   //TODO

}

void ImagemCImg::rotacionar(double angulo) const{

   //TODO

}

void ImagemCImg::salvar(const char* localSaida) const {

    imagem.save(localSaida);

}
