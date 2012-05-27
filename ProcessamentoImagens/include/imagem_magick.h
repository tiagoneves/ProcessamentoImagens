#ifndef IMAGEM_MAGICK_H
#define IMAGEM_MAGICK_H

#include "imagem.h"
#include <Magick++.h>

using namespace std;
using namespace Magick;

class ImagemMagick : public Imagem{

    public:

        ImagemMagick(const char* caminho);

        virtual void redimensionar(int fatorX, int fatorY) const;

        virtual void salvar() const;

        //virtual void converter(const string output)const;

        //virtual void crop(double cx, double cy, int width, int height)const;

        //virtual void rotacionar(double cx, double cy, double angulo)const;

};

#endif // IMAGEM_MAGICK_H