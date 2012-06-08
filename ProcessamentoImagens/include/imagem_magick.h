#ifndef IMAGEM_MAGICK_H
#define IMAGEM_MAGICK_H

#include "imagem.h"
#include <Magick++.h>

using namespace std;
using namespace Magick;

class ImagemMagick : public Imagem{

    public:

        ImagemMagick(const char* caminhoEntrada);

        virtual void redimensionar(double width, double height) const ;

        virtual void salvar(const char* localSaida) const;

        virtual void converter(const string output) const ;

        virtual void crop(double xUp, double yUp, double xLow, double yLow) const ;

        virtual void rotacionar(double cx, double cy, double angulo) const ;

};

#endif // IMAGEM_MAGICK_H
