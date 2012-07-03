
#ifndef COMUM_H
#define COMUM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "imagem.h"
#include "excecoes.h"

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

};

#endif
