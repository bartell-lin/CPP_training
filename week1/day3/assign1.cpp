#include <vector>
#include <iostream>
#include "assert.h"


int main() {
	float arr[] = {1.2, 2.3, 5.2};
	std::vector<float> vec;
	for (float i: arr) {
		vec.push_back(i);
	}

	for (float i: vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	assert(arr[0] == vec[0]);
	assert(arr[1] == vec[1]);
	assert(arr[2] == vec[2]);

}
