#include "Fractal.h"
#include "Grid.h"
#include <algorithm>

Fractal::Fractal() : max_iterations(50) {};
Fractal::Fractal(int iterations) : max_iterations(50) {};
Fractal::~Fractal() {

}



void Fractal::make_mandelbrot(std::vector<std::vector<std::complex<double>>> coords) {
	// map grid.grid -> iterations_grid
	
	std::vector<int> iterations_row{};
	for (std::vector<std::complex<double>> coord_row : coords) {
		iterations_row.clear();
		//std::transform(coord_row.begin(), coord_row.end(), iterations_row.begin(), mandelbrot_closure);
		for (std::complex<double> c : coord_row) {
<<<<<<< HEAD
			iterations_row.emplace_back(mandelbrot_iterate(c));
=======
			iterations_row.emplace_back(julia_iterate(c));
>>>>>>> dev
		}
		this->iterations_grid.push_back(iterations_row);
	}
}



// function to take a complex coord and calculate its total iterations
int Fractal::mandelbrot_iterate(std::complex<double> const &constant) {
	std::complex<double> z { 0.0, 0.0 };
	for (int i = 0; i < this->max_iterations; i++) {
		z = std::pow(z, 2) + constant;
		if (std::norm(z) >= 4) {
			return i;
		}
	}
	return 0;
}

<<<<<<< HEAD
=======
int Fractal::julia_iterate(std::complex<double> z) {
	std::complex<double> c{ 0.0, 0.0 };
	for (int i = 0; i < this->max_iterations; i++) {
		z = std::pow(z, 2) + c;
		if (std::norm(z) >= 4) {
			return i;
		}
	}
	return 0;
}
>>>>>>> dev
