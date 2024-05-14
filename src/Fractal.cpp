#include "Fractal.h"
#include "Grid.h"
#include <algorithm>

FractalGrid::FractalGrid(int iterations, FractalType fractal_type) : max_iterations(iterations), fractal_type(fractal_type)
{

}
FractalGrid::~FractalGrid() {

}



void FractalGrid::generate_fractal(std::vector<std::vector<std::complex<double>>> coords) {
	std::vector<int> iterations_row{};
	switch (fractal_type) {

	case FractalType::mandelbrot:
	{
		for (std::vector<std::complex<double>> coord_row : coords) {
			iterations_row.clear();
			//std::transform(coord_row.begin(), coord_row.end(), iterations_row.begin(), mandelbrot_closure);
			for (std::complex<double> c : coord_row) {
				iterations_row.emplace_back(mandelbrot_iterate(c));
			}
			this->iterations_grid.push_back(iterations_row);
		}
		break;
	}
	case FractalType::julia:
	{
		for (std::vector<std::complex<double>> coord_row : coords) {
			iterations_row.clear();
			//std::transform(coord_row.begin(), coord_row.end(), iterations_row.begin(), mandelbrot_closure);
			for (std::complex<double> c : coord_row) {
				iterations_row.emplace_back(julia_iterate(c));
			}
			this->iterations_grid.push_back(iterations_row);
		}
		break;
	}
	case FractalType::multi:
	{
	}

	default:
		break;
	}

	
}



int FractalGrid::mandelbrot_iterate(std::complex<double> const &constant) {
	std::complex<double> z { 0.0, 0.0 };
	for (int i = 0; i < this->max_iterations; i++) {
		z = std::pow(z, 2) + constant;
		if (std::norm(z) >= 4) {
			return i;
		}
	}
	return 0;
}

int FractalGrid::julia_iterate(std::complex<double> z) {
	std::complex<double> c{ -0.86, 0.24 };
	for (int i = 0; i < this->max_iterations; i++) {
		z = std::pow(z, 2) + c;
		if (std::norm(z) >= 4) {
			return i;
		}
	}
	return 0;
}