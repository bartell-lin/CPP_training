#include "BigNumber.h"
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


string BigNumber::number() const {
	if (overflow) {
		string s(actualUnion.cnum, actualUnion.cnum + len);
		return s;
	} else {
		return to_string(actualUnion.lnum);
	}
}

void BigNumber::set(long num) {
	actualUnion.lnum = num;
}

void BigNumber::set(string num) {
	if (overflow) {
		len = num.size();
		strcpy(reinterpret_cast<char *>(actualUnion.cnum), num.c_str());
	} else {
		string::size_type sz;
		long snum = std::stol (num, &sz);
		actualUnion.lnum = snum;
	}
} 

BigNumber::BigNumber(long num) {
	overflow = false;
	set(num);
}

BigNumber::BigNumber(string num) {
	if (num.length() > 18) {
		overflow = true;
	} else {
		overflow = false;
	}
	set(num);
}

BigNumber BigNumber::multiply(const BigNumber& input) const{
	string n1 = number();
	string n2 = input.number();

	if (!overflow && !input.overflow) {
		string::size_type sz;
		long ln1 = std::stol (n1, &sz);
		long ln2 = std::stol (n2, &sz);

		if (ln1 < LONG_MAX / ln2) {
			long prod = ln1 * ln2;
			BigNumber out(prod);
			return out;
		}
	}


	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int* ans = new int[n1.size() + n2.size()]();
	
	for (int i = 0; i < n1.size(); i++) {
		for (int j = 0; j < n2.size(); j++) {
			ans[i + j] += ((n1[i] - '0') * (n2[j] - '0'));
			ans[i + j + 1] += ((ans[i + j])/10);
			ans[i + j] = (ans[i + j]) % 10;
		}
	}
	

	string temp;
	for (int i = n1.size() + n2.size(); i --> 0; ) {
  		temp.push_back(ans[i] + '0');
	}
	temp.erase(0, min(temp.find_first_not_of('0'), temp.size()-1));
	BigNumber out(temp);

	delete[] ans;
	return out;
}

numvec BigNumber::simulate_multiply(BigNumber& input) {
	numvec v;
	string num = number();
	vector<unsigned char> n1(num.begin(), num.end());
	v.push_back(n1);
	string num2 = input.number();
	vector<unsigned char> n2(num2.begin(), num2.end());
	v.push_back(n2);

	for (int i = num2.size() - 1; i >= 0; i--) {
		BigNumber temp(num2[i] - '0');
		BigNumber tempout = multiply(temp);
		string x = tempout.number();
		vector<unsigned char> tvec(x.begin(), x.end());
		v.push_back(tvec);
	}

	BigNumber tempout = multiply(input);
	string x = tempout.number();
	vector<unsigned char> tvec(x.begin(), x.end());
	v.push_back(tvec);

	return v;

}

void BigNumber::print(numvec v) const {
	int totalspace = v[v.size() - 1].size();
	int space = totalspace - v[0].size();
	for (int k = 0; k < space; k++) {
		cout << " ";
	} 
	for (auto i:v[0]) {
		cout << i;
	}
	cout << endl;
	cout << "x";
	space = totalspace - v[1].size() - 1;
	for (int k = 0; k < space; k++) {
		cout << " ";
	} 
	for (auto i: v[1]) {
		cout << i;
	}
	cout << endl;
	cout << "-------" << endl;


	int i;
	int line = 0;
	for (i = 2; i < v.size() - 1; i++) {
		int space = totalspace - v[i].size() - line;
		for (int k = 0; k < space; k++) {
			cout << " ";
		} 
		for (auto j: v[i]) {
			cout << j;
		}
		for (int l = 0; l < line; l++) {
			cout << 0;
		}
		cout << endl;
		line++;
	}
	cout << "-------" << endl;

	for (auto j: v[i]) {
		cout << j;
	}
	cout << endl;

}




