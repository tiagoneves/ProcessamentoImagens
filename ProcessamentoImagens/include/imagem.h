#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>

using namespace std;

class Imagem {

    protected:

        const char* local;

        int width;

        int height;
	
	const char* obterNomeArquivo(const char* diretorioSaida);

    public:

        Imagem(const char* caminhoEntrada);

        const char* getLocal() const;
	
	void setLocalSaida(const char* diretorioSaida);

        const char* obterLocalSaida(const char* diretorioSaida);

        virtual void redimensionar(double width, double height) const = 0;;

        virtual void salvar(const char* localSaida) const = 0;

        virtual void converter(const string output) const = 0;

        virtual void crop(double xUp, double yUp, double xLow, double yLow) const = 0;

        virtual void rotacionar(double angulo) const = 0;

	virtual void equalizarHistograma() const = 0;

};


#endif
