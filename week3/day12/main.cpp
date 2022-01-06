#include "MyString.h"
#include <iostream>
#include <cassert>

using namespace std;


int main() {
	char str[] = {"abc"};
	MyString s = str;

	MyString s2 = s + s;
	assert(strcmp(s2.mstring, "abcabc") == 0);	

	MyString s3 = s * 3;
	assert(strcmp(s3.mstring, "abcabcabc") == 0);

	assert(s[2] == 'c');

	assert(strcmp((s + 1), "bc") == 0);	

	cout << "asserts passed" << endl;
}