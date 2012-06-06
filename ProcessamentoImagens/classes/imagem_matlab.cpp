
#include "../include/imagem_matlab.h"
#include "../include/excecoes.h"


ImagemMatlab::ImagemMatlab(const char* caminhoEntrada)  : Imagem (caminhoEntrada){

    if (!(ep = engOpen("\0"))) 
		
	throw ConnectException("Não foi possível conectar-se ao MATLAB");	

    mxArray* mxCaminhoEntrada = mxCreateString(caminhoEntrada);

    memcpy((void *)mxGetPr(mxCaminhoEntrada), (void *)caminhoEntrada, sizeof(caminhoEntrada));

    engPutVariable(ep, "nomeArquivo", mxCaminhoEntrada);

    engEvalString("I = imread(filename)");
    
}

void ImagemMatlab::redimensionar(double width, double height) const{

    //TODO
}

void ImagemMatlab::converter(const string output) const{

   //TODO

}

void ImagemMatlab::crop(double cx, double cy, int width, int height)const{

   //TODO

}

void ImagemMatlab::rotacionar(double cx, double cy, double angulo) const{

   //TODO


}

void ImagemMatlab::salvar(const char* localSaida) const {

    //TODO

}
