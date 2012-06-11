g++ -o release/cimg main/cimg.cpp classes/comum.cpp classes/excecoes.cpp classes/imagem.cpp classes/imagem_cimg.cpp -O2 -L/usr/lib -L/usr/local/lib -lm -lpthread -lX11 -I/home/tiago/Programas/CImg-1.4.9 -I/include/comum.h -I/include/excecoes.h -I/include/imagem.h -I/include/imagem_opencv.h
#g++ -g -o debug/cimg main/cimg.cpp classes/comum.cpp classes/excecoes.cpp classes/imagem.cpp classes/imagem_cimg.cpp -O2 -L/usr/lib -lm -lpthread -lX11 -I/home/tiago/Programas/CImg-1.4.9 -I/include/comum.h -I/include/excecoes.h -I/include/imagem.h -I/include/imagem_opencv.h



