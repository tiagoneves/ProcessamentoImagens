
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

    salvar();

}

void ImagemMagick::salvar() const {


    imagem.write(localSaida);

}

void ImagemMagick::converter(const string output) const {

   //TODO implementar

}

void ImagemMagick::crop(double cx, double cy, int width, int height) const {

    Geometry geom = imagem.size();

    double xTop = cx - width / 2;
    double yTop = cy + height / 2;
    double xBottom = cx + width / 2;
    double yBottom = cy - height / 2;

    imagem.chop(Geometry(xTop, yTop));
    imagem.crop(Geometry(xBottom, yBottom));
    
    salvar();

}

void ImagemMagick::rotacionar(double cx, double cy, double angulo) const {

    //TODO implementar

}

