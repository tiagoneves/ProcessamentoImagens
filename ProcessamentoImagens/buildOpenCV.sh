g++ -o release/opencv main/opencv.cpp classes/comum.cpp classes/excecoes.cpp classes/imagem.cpp classes/imagem_opencv.cpp `pkg-config opencv --cflags --libs` -I/include/comum.h -I/include/excecoes.h -I/include/imagem.h -I/include/imagem_opencv.h
g++ -g -o debug/opencv main/opencv.cpp classes/comum.cpp classes/excecoes.cpp classes/imagem.cpp classes/imagem_opencv.cpp `pkg-config opencv --cflags --libs` -I/include/comum.h -I/include/excecoes.h -I/include/imagem.h -I/include/imagem_opencv.h 


