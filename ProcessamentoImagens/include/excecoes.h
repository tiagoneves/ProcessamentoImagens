#ifndef EXCECOES_H
#define EXCECOES_H

using namespace std;

class BaseException {

    protected:

        const char* mensagem;

    public:

        BaseException(const char* msg);

        const char* obterMensagem();

};

class FileNotFoundException : public BaseException {

    public:

        FileNotFoundException();

        FileNotFoundException(const char* msg);

};

class NotSupportedOperationException : public BaseException {

    public:

        NotSupportedOperationException();

        NotSupportedOperationException(const char* msg);


};


#endif
