
#include "../include/imagem_magick.h"

Image imagem;

ImagemMagick::ImagemMagick(const char* caminho) : Imagem (caminho) {

    const string nomeArquivo(caminho);

    imagem.read(nomeArquivo);

}

void ImagemMagick::redimensionar(int fatorX, int fatorY) const {

    Geometry geom = imagem.size();

    imagem.zoom(Geometry());

    salvar();

}

void ImagemMagick::salvar() const {


    imagem.write(local);

}

void ImagemMagick::converter(const string output) const {

   //TODO implementar

}

void ImagemMagick::crop(double cx, double cy, int width, int height) const {

    //TODO implementar

}

void ImagemMagick::rotacionar(double cx, double cy, double angulo) const {

    //TODO implementar

}

