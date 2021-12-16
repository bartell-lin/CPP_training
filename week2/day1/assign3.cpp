#include <iostream>
#include "assert.h"

using namespace std;
bool check_power(int x);

int main() {

	assert(check_power(16) == true);
	assert(check_power(128) == true);
	assert(check_power(14) == false);
	assert(check_power(72) == false);
	assert(check_power(2048) == true);
}

bool check_power(int x) {
	int pow = 2;
	while (pow < x) {
		pow += pow;
	}
	if (pow == x) {
		return true;
	} else {
		return false;
	}
}