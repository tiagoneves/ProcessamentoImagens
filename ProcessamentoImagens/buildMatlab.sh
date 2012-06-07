# export LD_LIBRARY_PATH=/usr/local/MATLAB/R2011a/bin/glnxa64:/usr/local/MATLAB/R2011a/sys/os/glnxa64
mex -outdir release/ -f engopts.sh main/matlab.cpp classes/comum.cpp classes/excecoes.cpp classes/imagem.cpp classes/imagem_matlab.cpp
#mex -f engopts.sh main/matlab.cpp
