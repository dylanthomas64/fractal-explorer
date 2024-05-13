#pragma once
#include<vector>
#include<complex>

// a grid of complex numbers ready to be mapped onto pixels
class Grid {
public:
	// constructors
	Grid(int w, int h);
	~Grid();
	std::vector<std::vector<std::complex<double>>> get();
	void make_grid();

private:
	//screen pixel dimension
	int w;
	int h;
	//top left
	std::complex<double> c_zero;
	// range of real values
	double range;

	//2d vector of complex numbers
	std::vector<std::vector<std::complex<double>>> cartesian_grid;

};
