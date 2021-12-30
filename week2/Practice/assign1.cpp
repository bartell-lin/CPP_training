#include <iostream>
#include "BigNumber.h"


using namespace std;


int main() {

	// string in1;
	// string in2;
	// cout << "Input first number: ";
	// cin >> in1;
	// cout << "Input second number: ";
	// cin >> in2;
	// BigNumber n(in1);
	// BigNumber x(in2);

	BigNumber n(124);
	BigNumber x(456);
	numvec nv = n.simulate_multiply(x);
	n.print(nv);
}