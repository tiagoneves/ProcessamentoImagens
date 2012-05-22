#ifndef EXCECOES_H
#define EXCECOES_H

using namespace std;

class FileNotFoundException {

    private:

        const char* mensagem;

    public:

        FileNotFoundException();

        const char* obterMensagem();

};


#endif
