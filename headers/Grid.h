#pragma once
#include<vector>
#include<complex>

// a grid of complex numbers ready to be mapped onto a fractal set
class Grid {
public:
	// constructors
	Grid(int w, int h, std::complex<double> c_zero, int range);
	~Grid();

	// getters
	std::vector<std::vector<std::complex<double>>> get();
	void set(std::complex<double> c_zero, int range);

private:
	//screen pixel dimensions
	int w;
	int h;

	//top left pixel complex coord
	std::complex<double> c_zero;

	// range of real values (RealMax - RMin)
	double range;

	//2d vector of complex numbers
	std::vector<std::vector<std::complex<double>>> grid;

	//generate a grid
	void make_grid();

};