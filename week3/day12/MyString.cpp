#include "MyString.h"
#include <cstring>


MyString::MyString(char* str) {
	mstring = str;
}
	
MyString::~MyString() {
}

MyString::MyString(const MyString& other) {
	mstring = other.mstring;
}

MyString& MyString::operator=(const MyString& other) {
	if (this == &other) return *this;
	mstring = other.mstring;
	return *this;
}

MyString::MyString(MyString&& other) {
	mstring = other.mstring;
	other = nullptr;
}

MyString& MyString::operator=(MyString&& other) {
	if (this == &other) return *this;
	mstring = other.mstring;
	other = nullptr;
	return *this;
}

	
MyString MyString::operator+(const MyString& other) {
	char out[128] = {0};
	strcat(out, mstring);
	strcat(out, other.mstring);
	return MyString(out);
}

char* MyString::operator+(int x) {
	return &mstring[x];
}

MyString MyString::operator*(int x) {
	char out[128] = {0};
	for (int i = 0; i < x; i++) {
		strcat(out, mstring);
	}
	return MyString(out);
}

char& MyString::operator[](int x) {
	return mstring[x];
}

