#include <iostream>

#include <string.h>

#include "../include/imagem_magick.h"
#include "../include/excecoes.h"

#include "../include/comum.h"

int main(int argc, char **argv) {


	Imagem *imagem = new ImagemMagick(argv[2]);

	Comum comum(imagem);

	return comum.operar(argv);	


}
