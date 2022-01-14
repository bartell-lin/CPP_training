#include "MyVector.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main() {
	myvector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.insert(2, 30);

	assert(v.size() == 5);
	

	int c = 0;
	for (auto it = v.begin(), end = v.end(); it != end; ++it) {
		const auto i = *it;
		assert(i == v[c++]);
	}

	myvector<string> s;
	s.push_back("hello");
	s.push_back("world");
	s.push_back("this");
	s.push_back("is");
	s.push_back("a");
	s.push_back("test");

	c = 0;
	for (auto it = s.begin(), end = s.end(); it != end; ++it) {
		const auto i = *it;
		assert(i == s[c++]);
	}
	s.clear();
	assert(s.size() == 0);

	myvector<int> v2 = v;
	v2.push_back(60);
	assert(v2.size() > v.size());
	v2.pop_back();
	assert(v2 == v);

	myvector<int> v3 = move(v2);
	assert(v3.size() == 5);


	cout << "asserts passed" << endl;
}