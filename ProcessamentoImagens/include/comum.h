
#include <iostream>

#include "include/imagem_opencv.h"
#include "include/imagem_magick.h"
#include "include/excecoes.h"
#include <string.h>

#ifndef COMUM_H
#define COMUM_H

using namespace std;

class Comum {


     private:

	Imagem *imagem;

     public:

	Comum(Imagem *img);

	int operar(char **argv);

	const char* trocarExtensao(const char* local, const char* extensao) ;

	string copiarNPrimeirosCaracteres(const char* src, int qtd) ;

	string adicionarExtensao(string src, const char* ext);

}

#endif
