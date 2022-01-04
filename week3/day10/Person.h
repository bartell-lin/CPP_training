#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	int index;
	Person(string n);
public:
	Person();
	~Person();
	string name;
	int count;
	static Person* persons[10];
	static Person* getPerson(string name);
};