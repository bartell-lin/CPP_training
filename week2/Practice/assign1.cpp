#include <iostream>
#include "BigNumber.h"


using namespace std;


int main() {
	BigNumber n(124);
	BigNumber x(456);
	BigNumber out = n.multiply(x);
	// numvec nv = n.simulate_multiply(x);
	// n.print(nv);
	cout << out.number() << endl;
}