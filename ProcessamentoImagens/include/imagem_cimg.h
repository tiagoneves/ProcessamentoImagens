#ifndef IMAGEM_CIMG_H
#define IMAGEM_CIMG_H

#include "imagem.h"
#include "CImg.h"

using namespace std;
using namespace cimg_library;

class ImagemCImg : public Imagem{

    public:

        ImagemCImg(const char* caminhoEntrada);

        virtual void redimensionar(double width, double height) const;

        virtual void salvar(const char* localSaida) const;

        virtual void converter(const string output) const;

        virtual void crop(double xUp, double yUp, double xLow, double yLow) const;

        virtual void rotacionar(double cx, double cy, double angulo) const;

};


#endif // IMAGEM_CIMG_H
