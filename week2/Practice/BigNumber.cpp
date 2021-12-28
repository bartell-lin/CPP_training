#include "BigNumber.h"

using namespace std;


string BigNumber::number() const {
	if (overflow) {
		string res(actualUnion.cnum, actualUnion.cnum + 64);
		return res;
	} else {
		return to_string(actualUnion.lnum);
	}
}

void BigNumber::set(long num) {
	actualUnion.lnum = num;
}

void BigNumber::set(string num) {
	if (overflow) {
		actualUnion.cnum = num;
	} else {
		// actualUnion.lum = 
	}
} 

BigNumber::BigNumber(long num) {
	overflow = false;
	bnumber = num;
}

BigNumber::BigNumber(string num) {
	overflow = false;
	string::size_type sz;
	long snum = std::stol (str_dec,&sz);
	bnumber = snum;
}

void BigNumber::multiply(const BigNumber& input, BigNumber& output) {
	long temp = 0;
	for (int i = 0; i < bnumber; i++) {
		temp += input.bnumber;
	}
	output.set(temp);
	 
}

numvec BigNumber::simulate_multiply(BigNumber& input) {
	numvec v;
	
}






