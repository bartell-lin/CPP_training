#include  <iostream>
#include <cassert>

using namespace std;

int main() {
	assert(3 == 3.0); // Passes because float precision did not kick in

	float x = 3.1;  
	
	assert(x == 3.1); // Fails because float precision kicks in and causes a rounding error between float and double.  
	
	assert(3.1 == 3.1); // Passes because both are literals of the same value
	
	assert(true == 1.0); // Passes because the true boolean has a value of 1
	
	assert('a' == 97); // Passes becuase the char 'a' has an ASCII value of 97 
	
	int* p = 0;
	
	assert(NULL == p); //  Passes because it is a null pointer and NULL and 0 are equivalent as seen below 
	
	assert(NULL == 0); // Passes because in C++ the definition of NULL is 0
}