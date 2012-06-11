
#include "../include/imagem_magick.h"

#include <iostream>

Image image;

ImagemMagick::ImagemMagick(const char* caminhoEntrada) : Imagem (caminhoEntrada) {

    const string nomeArquivo(caminhoEntrada);

    /*Image img("dragon.gif");
    img.resize("64x64");
    img.write("../saida/dragon.gif");
    image = img;*/

   Image img(caminhoEntrada);
   image = img;

}

void ImagemMagick::redimensionar(double width, double height) const {

    //Geometry geom = imagem.size();

    //imagem.zoom(Geometry(geom.width() * fatorX, geom.height() * fatorY));

    //double x = geom.width();
    //double y = geom.height();

    Geometry size = image.size();

    double a = size.width();
    double b = size.height();

    printf("%f\n", a);
    printf("%f\n", b);

    //Geometry nSize = Geometry(width, height);
    //Geometry nSize = Geometry("68x68");

    //image.zoom( Geometry(a * 2, b * 1.5));

image.rotate(45);


    //image.resize(nSize);



}

void ImagemMagick::salvar(const char* localSaida) const {
 
    image.write(localSaida);

}

void ImagemMagick::converter(const string output) const {

   //TODO implementar

}

void ImagemMagick::crop(double xUp, double yUp, double xLow, double yLow) const {

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

    image.chop(Geometry(xUp, yUp));
    image.crop(Geometry(xLow, yLow));

}

void ImagemMagick::rotacionar(double cx, double cy, double angulo) const {

    //TODO implementar

}

