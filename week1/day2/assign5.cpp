/* You can measure the precision of a floating point number by how many digits it has. 
*/
#include "assert.h"
#include <iostream>

int main() {
	float a = 1000000000.23;
    float b = 1000000000.45;


	assert(a != b); // This fails because a float does not have enough bits to represent the whole number to tell the difference.
}