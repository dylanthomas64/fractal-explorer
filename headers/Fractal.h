#pragma once
#include<vector>
#include<complex>

enum class FractalType {mandelbrot, julia};


// 2dvector of ints mapped from Grid, representing a fractal set e.g. escape velocity
class FractalGrid
{
public:
	FractalGrid(int iterations = 50);
	~FractalGrid();

	// variables
	int max_iterations;

	// fractaltype

	// algorithms
	int mandelbrot_iterate(std::complex<double> const &constant);
	int julia_iterate(std::complex<double> constant);

	// aesthetic
	// TODO


	//2d vector of iteration values for each pixel
	std::vector<std::vector<int>> iterations_grid{};


	// convert a grid of complex points to a grid of iterations
	void generate_fractal(std::vector<std::vector<std::complex<double>>> coords);



};
