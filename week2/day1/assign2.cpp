#include <iostream>
using namespace std;

struct A {
	void myfunc(float f) {cout << "non const" << endl;};
	void myfunc(float f) const {cout << "const" << endl;};
};


int main() {
	float x = 3.2;
	A a;
	a.myfunc(x);
	const A b = a;
	b.myfunc(x);
}