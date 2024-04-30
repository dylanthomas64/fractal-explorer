#pragma once
#include<vector>
#include<complex>


//2dvector of speed of escape represenentation of the pixels on the screen
class Fractal
{
public:
	Fractal();
	Fractal(int iterations);
	~Fractal();

	// variables

	int max_iterations;

	//algorithm lambdas
	int mandelbrot_iterate(std::complex<double> const &constant);

<<<<<<< HEAD
=======
	int julia_iterate(std::complex<double> constant);
>>>>>>> dev
	//aesthetic



	//2d vector of iteration values for each pixel
	std::vector<std::vector<int>> iterations_grid{};


	// convert a grid of complex points to a grid of iterations
	void make_mandelbrot(std::vector<std::vector<std::complex<double>>> coords);
	//converts a single complex point to its number of iterations
	//void make_julia(Grid grid);



};
