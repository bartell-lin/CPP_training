#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

void approx(float x);

int main() {
	approx(.1);
	approx(.125);
	approx(.3);
}

void approx(float x) {
	int N = 1;

	while (int y = pow(2, N) * x < pow(2, 53)) {
		N++;
	}
	N--;

	long J = pow(2, N) * x;
	float apx = J / pow(2, N);


	cout << "J: " << J << endl;
	cout << "N: " << N << endl;
	cout << "Approx: " << setprecision(53) << apx << endl;
}