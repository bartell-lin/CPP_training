#include "Sentence.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	char mystring[]{"Quick brown fox jumps over the lazy dog."};
	char mystring2[]{"new string to replace old one"};

	Sentence sent(mystring);
	Sentence copy = sent; //prints copy constructor is called 
	assert(copy.data() == sent.data());

	copy = Sentence(mystring2); // prints copy assignment is called 
	assert(copy.data() == mystring2);

	Sentence original(mystring);
	Sentence mv = move(original); // prints move constructor is called 
	assert(mv.data() == mystring);
	assert(original.data() == nullptr);


	// since overload resolution selects move assignment over copy assignment, I am using == to differentiate between the two
	mv == Sentence(mystring2); // prints move assignment is called 

}