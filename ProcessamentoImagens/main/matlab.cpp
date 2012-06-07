#include <iostream>

#include "../include/imagem_matlab.h"
#include "../include/excecoes.h"

#include "../include/comum.h"

int main(int argc, char **argv) {


	Imagem *imagem = new ImagemMatlab(argv[2]);

	Comum comum(imagem);

	return comum.operar(argv);	


}
