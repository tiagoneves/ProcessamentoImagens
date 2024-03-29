
#include "../include/imagem_matlab.h"
#include "../include/excecoes.h"

ImagemMatlab::ImagemMatlab(const char* caminhoEntrada)  : Imagem (caminhoEntrada){

    if (!(engine = engOpen("\0"))) 
		
	throw ConnectException("Não foi possível conectar-se ao MATLAB");	

    mxArray* mxCaminhoEntrada = mxCreateString(caminhoEntrada);

    //memcpy((void *)mxGetPr(mxCaminhoEntrada), (void *)caminhoEntrada, sizeof(caminhoEntrada));

    engPutVariable(engine, "nomeArquivo", mxCaminhoEntrada);

    engEvalString(engine, "A = imread(nomeArquivo)");
    
}

void ImagemMatlab::redimensionar(double width, double height) const{
	
	double size[2] = {width, height};
	
	mxArray* mxSize = mxCreateDoubleMatrix(1, 2, mxREAL);

	memcpy((void *)mxGetPr(mxSize), (void *)size, sizeof(size));

	engPutVariable(engine, "size", mxSize);

	engEvalString(engine, "B = imresize(A, size)");    

}

void ImagemMatlab::converter(const string output) const{

   //TODO

}

void ImagemMatlab::crop(double xUp, double yUp, double xLow, double yLow) const {

   double rect[4] = {xUp, yUp, xLow, yLow};
	
   mxArray* mxSize = mxCreateDoubleMatrix(1, 4, mxREAL);

   memcpy((void *)mxGetPr(mxSize), (void *)rect, sizeof(rect));

   engPutVariable(engine, "rect", mxSize);

   engEvalString(engine, "B = imcrop(A, rect)");

}

void ImagemMatlab::rotacionar(double angulo) const {

   double ang[1] = {angulo};

   mxArray* mxSize = mxCreateDoubleMatrix(1, 1, mxREAL);
   
   memcpy((void *)mxGetPr(mxSize), (void *)ang, sizeof(ang));

   engPutVariable(engine, "angulo", mxSize);

   engEvalString(engine, "B = imrotate(A, angulo)");

}

void ImagemMatlab::salvar(const char* localSaida) const {

     mxArray* mxLocalSaida = mxCreateString(localSaida);

    //memcpy((void *)mxGetPr(mxCaminhoEntrada), (void *)caminhoEntrada, sizeof(caminhoEntrada));

    engPutVariable(engine, "saida", mxLocalSaida);

    engEvalString(engine, "imwrite(B, saida)");  

}
