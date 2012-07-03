
#include "../include/excecoes.h"

using namespace std;

BaseException::BaseException(const char* msg)
    :mensagem (msg){}

const char* BaseException::obterMensagem(){

    return mensagem;

}

FileNotFoundException::FileNotFoundException(const char* msg)
    :BaseException (msg){}

FileNotFoundException::FileNotFoundException()
    :BaseException ("Não foi possível abrir o arquivo especificado"){}


NotSupportedOperationException::NotSupportedOperationException(const char* msg)
    :BaseException (msg){}

NotSupportedOperationException::NotSupportedOperationException()
    :BaseException ("Não é possível realizar a operação"){}

ConnectException::ConnectException(const char* msg)
    :BaseException (msg){}

ConnectException::ConnectException()
    :BaseException ("Erro de conexão"){}

