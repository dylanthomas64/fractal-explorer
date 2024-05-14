# FractalExplorer

Generates mandelbrot and julia fractals

requires SDL2

# Installation with package manager

install sdl with your package manager
https://wiki.libsdl.org/SDL2/Installation

```bash
mkdir build

cd build

cmake ..

cmake --build .
```


If SDL2 can't be located, then add the root folder containing the lib and cmake files to "MAKE_INSTALL_PREFIX":

```bash
cmake -DCMAKE_INSTALL_PREFIX="@PATH@" ..
```
e.g. PATH="C:/VSLib/SDL2-2.28.4"

OR you update the MAKE_INSTALL_PREFIX list in CMakeLists.txt

