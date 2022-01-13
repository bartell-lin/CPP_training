#include "Account.h"

float Convert::operator()(Euro e) {
	return e.value / .87;
}
float Convert::operator()(Pound p) {
	return p.value / .73;
}
float Convert::operator()(Yen y) {
	return y.value / 114.56;
}
float Convert::ret(Euro e) {
	return e.value * .87;
}
float Convert::ret(Pound p) {
	return p.value * .73;
}
float Convert::ret(Yen y) {
	return y.value * 114.56;
}