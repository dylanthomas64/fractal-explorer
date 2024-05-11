#include "Grid.h"
#include <complex>
#include<vector>

Grid::Grid(int w, int h) {
	this->w = w;
	this->h = h;
	//top left pixel
	c_zero = std::complex<double>(-2, 1.5);
	//width of grid cartesian grid
	range = 3;
	make_grid();

}

Grid::~Grid() {

}
void Grid::make_grid() {
	double increment = range / w;
	std::vector<std::vector<std::complex<double>>> grid{};
	double r0 = this->c_zero.real();
	double i0 = this->c_zero.imag();
	std::vector<std::complex<double>> row;
	for (int y = 0; y < h; y++) {
		row.clear();
		for (int x = 0; x < w; x++) {
			row.emplace_back(std::complex<double>(r0 + (x * increment), i0 - (y * increment)));
		}
		grid.push_back(row);
	}
	this->cartesian_grid = grid;
}

std::vector<std::vector<std::complex<double>>> Grid::get() {
	return this->cartesian_grid;
}