#include <iostream>
#include <complex>
#include <vector>
#include <chrono>
#include <functional>

#include "window.h"
#include "save_image.h"
#include "utils.h"

// clang++ -std=c++11 -stdlib=libc++ -O3 save_image.cpp utils.cpp mandel.cpp -lfreeimage

// Use an alias to simplify the use of complex type
using Complex = std::complex<double>;

// Convert a pixel coordinate to the complex domain
Complex scale(window<int> &scr, window<double> &fr, Complex c) {
	Complex aux(c.real() / (double)scr.width() * fr.width() + fr.x_min(),
		c.imag() / (double)scr.height() * fr.height() + fr.y_min());
	return aux;
}

// Check if a point is in the set or escapes to infinity, return the number if iterations
int escape(Complex c, int iter_max, const std::function<Complex( Complex, Complex)> &func) {
	Complex z(0);
	int iter = 0;

	while (abs(z) < 200000000.0 && iter < iter_max) {
		z = func(z, c);
		iter++;
	}

	return iter;
}

// Loop over each pixel from our image and check if the points associated with this pixel escape to infinity
void get_number_iterations(window<int> &scr, window<double> &fract, int iter_max, std::vector<int> &colors,
	const std::function<Complex( Complex, Complex)> &func) {
	int k = 0;
	for(int i = scr.y_min(); i < scr.y_max(); ++i) {
		for(int j = scr.x_min(); j < scr.x_max(); ++j) {
			Complex c((double)j, (double)i);
			c = scale(scr, fract, c);
			colors[k] = escape(c, iter_max, func);
			k++;
		}
	}
}

void fractal(window<int> &scr, window<double> &fract, int iter_max, std::vector<int> &colors,
	const std::function<Complex( Complex, Complex)> &func, const char *fname, bool smooth_color) {
	auto start = std::chrono::steady_clock::now();
	get_number_iterations(scr, fract, iter_max, colors, func);
	auto end = std::chrono::steady_clock::now();
	std::cout << "Time to generate " << fname << " = " << std::chrono::duration <double, std::milli> (end - start).count() << " [ms]" << std::endl;

	// Save (show) the result as an image
	plot(scr, colors, iter_max, fname, smooth_color);
}

void mandelbrot() {
	// Define the size of the image
	window<int> scr(0, 800, 0, 600);
	// The domain in which we test for points
	window<double> fract(-2.2, 1.2, -1.14, 1.14);

	// The function used to calculate the fractal
	auto func = [] (Complex z, Complex c) -> Complex {return z * z + c; };

	int iter_max = 500;
	bool smooth_color = true;
	
	//int iter_max = 5000;
	//bool smooth_color = false;
	
	const char *fname = "mandelbrot.png";
	std::vector<int> colors(scr.size());
	
	fractal(scr, fract, iter_max, colors, func, fname, smooth_color);
}

int main() {

	mandelbrot();

	return 0;
}

