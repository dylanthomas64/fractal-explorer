# FractalExplorer

generate mandelbrot and julias fractals

requires SDL2

# Installation with package manager

install sdl with your package manager
https://wiki.libsdl.org/SDL2/Installation


mkdir build

cd build

cmake ..

cmake --build .



#installation without package manager

assuming that SDL has a cmake folder with config files

cd build

cmake -DCMAKE_INSTALL_PREFIX="@PATH@" ..

cmake --build .

:)

e.g. PATH="C:/VSLib/SDL2-2.28.4"

OR you can update the MAKE_INSTALL_PREFIX list in CMakeLists.txt

