#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>
#include "cv.h"

using namespace std;
using namespace cv;

class Imagem {

    private:

        const char* local;

        IplImage *pImg;

        Mat matriz;

        Mat matProc;

        int width;

        int height;

    public:

        Imagem(const char* caminho);

        void redimensionar(int x, int y);

        void salvar();

        void converter(const string output);

        const char* getLocal();

        void crop(double cx, double cy, int width, int height);

};


#endif
