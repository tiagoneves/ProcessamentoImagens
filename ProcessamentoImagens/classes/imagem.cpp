
#include "../include/imagem.h"

Imagem::Imagem(const char* caminho) {

    local = caminho;

}

const char* Imagem::getLocal() const{

    return local;

}

