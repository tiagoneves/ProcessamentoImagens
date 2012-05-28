#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>

using namespace std;

class Imagem {

    protected:

        const char* local;

        int width;

        int height;

    public:

        Imagem(const char* caminho);

        const char* getLocal() const;

        virtual void redimensionar(int fatorX, int fatorY) const = 0;;

        virtual void salvar() const = 0;

        virtual void converter(const string output) const = 0;

        virtual void crop(double cx, double cy, int width, int height) const = 0;

        virtual void rotacionar(double cx, double cy, double angulo) const = 0;

};


#endif
