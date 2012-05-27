
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

