#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person() {
	index = 0;
}

Person::Person(string n) {
	name = n;
	count = 1;
	for (int i = 0; persons[i] != NULL; i++) {
		if (persons[i]->name == n) {
			count += persons[i]->count;
			delete persons[i];
			persons[i] = this;
		}
	}
	index++;
}

Person::~Person() {
	for (int i = 0; i < index - 1; i++) {
		delete persons[i];
	}
}

Person* Person::getPerson(string name) {
	Person* p = new Person(name);
	return p;
}

Person* Person::persons[10];