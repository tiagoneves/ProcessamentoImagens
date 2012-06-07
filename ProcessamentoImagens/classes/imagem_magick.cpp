
#include "../include/imagem_magick.h"

Image imagem;

ImagemMagick::ImagemMagick(const char* caminhoEntrada) : Imagem (caminhoEntrada) {

    const string nomeArquivo(caminhoEntrada);

    imagem.read(nomeArquivo);

}

void ImagemMagick::redimensionar(double width, double height) const {

    //Geometry geom = imagem.size();

    //imagem.zoom(Geometry(geom.width() * fatorX, geom.height() * fatorY));

    //double x = geom.width();
    //double y = geom.height();

    Geometry nSize = Geometry(width, height);
    //Geometry nSize = Geometry("68x68");

    nSize.aspect(false);

    imagem.resize(nSize);

}

void ImagemMagick::salvar(const char* localSaida) const {
 
    imagem.write(localSaida);

}

void ImagemMagick::converter(const string output) const {

   //TODO implementar

}

void ImagemMagick::crop(double xUp, double yUp, int xLow, int yLow) const {

    //Geometry geom = imagem.size();

    //int xTop = (int) cx - width / 2;
    //int yTop = (int) cy + height / 2;
    //int xBottom = (int) cx + width / 2;
    //int yBottom = (int) cy - height / 2;
  
   /* size_t oito = 8;
    size_t trinta_oito = 38;
    size_t quarenta_cinco = 45;
    size_t onze = 11;

    imagem.chop(Geometry(oito, trinta_oito));
    imagem.crop(Geometry(quarenta_cinco, onze));
    
    //salvar();*/

    imagem.chop(Geometry(xUp, yUp));
    imagem.crop(Geometry(xLow, yLow));

}

void ImagemMagick::rotacionar(double cx, double cy, double angulo) const {

    //TODO implementar

}

