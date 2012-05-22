
#include "../include/excecoes.h"

using namespace std;

FileNotFoundException::FileNotFoundException()
    :mensagem ("Não foi possível abrir o arquivo especificado"){}



const char* FileNotFoundException::obterMensagem(){

    return mensagem;

}
