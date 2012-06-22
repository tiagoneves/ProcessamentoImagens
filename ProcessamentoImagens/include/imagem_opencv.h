#ifndef IMAGEM_OPENCV_H
#define IMAGEM_OPENCV_H

#include "imagem.h"
#include "cv.h"
#include "highgui.h"

using namespace std;
using namespace cv;

class ImagemOpenCV : public Imagem{

    public:

        ImagemOpenCV(const char* caminhoEntrada);

        virtual void redimensionar(double width, double height) const;

        virtual void salvar(const char* localSaida) const;

        virtual void converter(const string output) const;

        virtual void crop(double xUp, double yUp, double xLow, double yLow) const;

        virtual void rotacionar(double angulo) const;

        virtual void equalizarHistograma() const;

	virtual void convolucao(int linhas, int colunas, double** mask) const;

};


#endif // IMAGEM_OPENCV_H
