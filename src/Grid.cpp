#include "Grid.h"
#include <complex>
#include<vector>

Grid::Grid(int w, int h, std::complex<double> c_zero, int range) : w(w), h(h), c_zero(c_zero), range(range) {
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
	this->grid = grid;
}

std::vector<std::vector<std::complex<double>>> Grid::get() {
	return this->grid;
}

void Grid::set(std::complex<double> c_zero, int range) {
	this->c_zero = c_zero;
	this->range = range;
}