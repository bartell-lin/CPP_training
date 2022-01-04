#include <iostream>
#include <string>
#include "Person.h"

using namespace std;


int main() {
	Person p;
	string names[5] = {"bob", "james", "janet", "bob", "stella"};

	for (int i = 0; i < 5; i++) {
		p.persons[i] = p.getPerson(names[i]);
		cout << p.persons[i]->name << ": " << p.persons[i]->count << endl;
	}

}