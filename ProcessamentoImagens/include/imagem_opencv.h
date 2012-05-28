#ifndef IMAGEM_OPENCV_H
#define IMAGEM_OPENCV_H

#include "imagem.h"
#include "cv.h"

using namespace std;
using namespace cv;

class ImagemOpenCV : public Imagem{

    private:

        IplImage *pImg;

        Mat matriz;

    public:

        ImagemOpenCV(const char* caminho);

        virtual void redimensionar(int x, int y) const;

        virtual void salvar()const;

        virtual void converter(const string output)const;

        virtual void crop(double cx, double cy, int width, int height)const;

        virtual void rotacionar(double cx, double cy, double angulo)const;

};


#endif // IMAGEM_OPENCV_H
