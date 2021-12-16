#include <iostream>
#include <vector>
#include "assign1.h"
#include "assert.h"

using namespace std;

typedef int (*fp) (int, int);
vector<fp> funcs;

int main() {
	funcs.push_back(&add);
	funcs.push_back(&subtract);
	funcs.push_back(&multiply);

	assert(compute(1, 2, 0b00000001) == 3);
	assert(compute(132, 7, 0b00000010) == 125);
	assert(compute(12, 3, 0b00000100) == 36);

}


int compute(int arg1, int arg2, unsigned char funcmask) {
	if (funcmask == 1) {
		return(*funcs[0])(arg1, arg2);

	} else if (funcmask == 2) {
		return(*funcs[1])(arg1, arg2);

	} else if (funcmask == 4) {
		return(*funcs[2])(arg1, arg2);
	} else {
		return -1;
	}
}

int add(int arg1, int arg2) {
	return arg1 + arg2;
}

int subtract(int arg1, int arg2) {
	return arg1 - arg2;
}

int multiply(int arg1, int arg2) {
	return arg1 * arg2;
}