#ifndef IMAGEM_MATLAB_H
#define IMAGEM_MATLAB_H

#include <string.h>

#include "imagem.h"
#include "engine.h"

using namespace std;

class ImagemMatlab : public Imagem{

    private:

	Engine *engine;

    public:

        ImagemMatlab(const char* caminhoEntrada);

        virtual void redimensionar(double width, double height) const;

        virtual void salvar(const char* localSaida) const;

        virtual void converter(const string output) const;

        virtual void crop(double cx, double cy, int width, int height) const;

        virtual void rotacionar(double cx, double cy, double angulo) const;

};


#endif // IMAGEM_MATLAB_H
