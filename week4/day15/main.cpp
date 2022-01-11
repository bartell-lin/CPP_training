#include <cassert>
#include <cmath>
#include <sstream>
#include <iostream>

bool compare_f(float x, float y) noexcept;


int main() {
	assert(compare_f(3.0, 3.0) == true);
	assert(compare_f(1.0, 2.0) == false);

	try {
		compare_f(6.0, 5.1);
	} catch (...) {
		std::cout << "Not reached" << std::endl; // Not reached because std::terminate is called due to noexcept
	}
}


bool compare_f(float x, float y) noexcept {
	if ((ceilf(x) == x) && (ceilf(y) == y)) {
		return x == y;
	} else {
		throw std::runtime_error("Not representable as integers");
	}
}