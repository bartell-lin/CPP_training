#include <iostream>
#include "BigNumber.h"


using namespace std;


int main() {
	BigNumber n(12);
	BigNumber x(5);
	BigNumber out(0);
	n.multiply(x, out);
	cout << out.bnumber << endl;
}