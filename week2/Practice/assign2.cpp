#include "Calandar.h"
#include <iostream>
#include <limits>
#include <typeinfo>
using namespace std;

int main() {
	int month;
	int year;
	while(1) {
		cout << "Enter Month: ";
		if (!(cin >> month)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		break;
	}

	if (month < 1 || month > 12) {
		cout << "Invalid month" << endl;
		return 0;
	}

	while(1) {
		cout << "Enter Year: ";
		if (!(cin >> year)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
			continue;
		}
		break;
	}

	Calandar cal(month, year);
	cal.print();
}