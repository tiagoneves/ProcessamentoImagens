#include <iostream>

#include "../include/imagem_cimg.h"
#include "../include/excecoes.h"

#include "../include/comum.h"

int main(int argc, char **argv) {


	Imagem *imagem = new ImagemCImg(argv[2]);

	Comum comum(imagem);

	return comum.operar(argv);	


}
