g++ -o release/imagemagick main/imagemagick.cpp classes/comum.cpp classes/excecoes.cpp classes/imagem.cpp classes/imagem_magick.cpp -I/include/comum.h -I/include/excecoes.h -I/include/imagem.h -I/include/imagem_magick.h `Magick++-config --cppflags --cxxflags --ldflags --libs`



