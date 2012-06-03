
#include "../include/imagem.h"
#include <string.h>

using namespace std;

Imagem::Imagem(const char* caminhoEntrada) {

    local = caminhoEntrada;


}

const char* Imagem::getLocal() const{

    return local;

}

const char* Imagem::obterNomeArquivo(const char* diretorioSaida) {

	char* nomeRef = strrchr((char*)local, '/');

        if (nomeRef == NULL)
		nomeRef = (char*)local;
	else
		nomeRef++;

	return &nomeRef[0];

}

const char* Imagem::obterLocalSaida(const char* diretorioSaida) {

	string nomeArquivo(obterNomeArquivo(diretorioSaida));

	string dirSaidaStr(diretorioSaida);

	dirSaidaStr += "/" + nomeArquivo;

	return dirSaidaStr.data();


}
