#include <iostream>

#include <string.h>

#include "../include/imagem_opencv.h"
#include "include/excecoes.h"

#include "comum.h"

int main(int argc, char **argv) {


	Imagem *imagem = new ImagemOpenCV(argv[2]);

	Comum comum(imagem);

	return comum.operar(argv);	


}
