#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "Sentence.h"
#include <iostream>

using namespace std;

Sentence::Sentence(char* sent) {
	sentence = sent;
	for (int i = 0; i < strlen(sentence); i++) {
		if (i == 0) {
			vsentence.push_back(i);
		}
		if (sentence[i] == ' ') {
			vsentence.push_back(i + 1);
		}
	}
}

Sentence::Sentence(const Sentence& other) {
	cout << "Copy constructor is called" << endl;
	sentence = other.sentence;
	vsentence = other.vsentence;
}

Sentence& Sentence::operator=(const Sentence& other) {
	cout << "Copy assignment is called" << endl;
	if (this == &other) return *this;
	sentence = other.sentence;
	vsentence = other.vsentence;
	return *this;
}

Sentence::Sentence(Sentence&& other) {
	cout << "Move constructor is called" << endl;
	sentence = other.sentence;
	vsentence = other.vsentence;
	other.sentence = nullptr;
	vsentence.clear();
}


Sentence& Sentence::operator==(Sentence&& other) {
	cout << "Move assignment is called" << endl;
	if (this == &other) return *this;
	sentence = other.sentence;
	vsentence = other.vsentence;
	other.sentence = nullptr;
	vsentence.clear();
	return *this;
}


char* Sentence::data() {
	return sentence;
}

int Sentence::num_words() const {
	return vsentence.size();
}


string Sentence::get_word(int n) {
	int offset = vsentence[n];
	int end;
	if (vsentence.size() == n) {
		end = strlen(sentence);
	} else {
		end = vsentence[n + 1];
	}
	string s(sentence);
	return s.substr(offset, end - offset);
	 
}

void Sentence::replace(char* sent) {
	sentence = sent;
}


Sentence::~Sentence() {
}