g++ -g classes/*.cpp main.cpp `pkg-config opencv --cflags --libs` -I./include `Magick++-config --cppflags --cxxflags --ldflags --libs`

