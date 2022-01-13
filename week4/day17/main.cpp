#include "Account.h"
#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;


int main() {
	Account<Euro> a(100);
	Account<Euro> b(200);

	static_assert(is_same_v<decltype(a), Account<Euro>>);

	a.deposit<Euro>(100);

	assert(a == b);

	a.withdraw<Euro>(100);

	a += a;

	assert(a == b);

	a.deposit<Pound>(145.53);
	b.withdraw<Dollar>(200);

	assert(a > b);

	Yen y = static_cast<Yen>(a);
	Account<Yen>* x = a.currency<Yen>();

	Account<Yen> c(y);
	assert(*x == c);
	delete x;

	Account<Yen> d = c;
	static_assert(is_same_v<decltype(d), Account<Yen>>);

	Account<Euro> e = move(b);

}