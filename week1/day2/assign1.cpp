#include <iostream>

int main() {
	std::string type;
	std::cout << "Enter a type: ";
	getline(std::cin, type);
	int size;
	if (type == "char" || type == "unsigned char" || type == "signed char" || type == "bool") {
		size = 1;
	} else if (type == "short int" || type == "unsigned short int" || type == "wchar_t" || type == "signed short int") {
		size = 2;
	} else if (type == "int" || type == "unsigned int" || type == "signed int" || type == "float") {
		size = 4;
	} else if (type == "long int" || type == "unsigned long int" || type == "signed long int" || type == "long long int" || type == "unsinged long long int" || type == "signed long long int" || type == "double") {
		size = 8;
	} else if (type == "long double") {
		size = 12;
	} else {
		size = 0;
		std::cout << "Not valid type";
	}

	std::cout << size << "\n";
}