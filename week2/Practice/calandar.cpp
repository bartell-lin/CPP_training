#include <ctime>
#include <iostream>
#include "Calandar.h"

using namespace std;

enum Months {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12};

Calandar::Calandar(int m, int y) {
	month = m;
	year = y;
	set(m, y);
}

Calandar::~Calandar() {
	for (int i = 0; cal[i] == nullptr; i++) {
		delete[] cal[i];
	}
	delete[] cal;
}

void Calandar::set(int month, int year) {
	tm time_in = {0, 0, 0, 1, month - 1, year - 1900};
	time_t temp = mktime(&time_in);
	tm* lt = localtime(&temp);

	int first  = lt->tm_wday;
	int num_days;
	if (month == Jan || month == Mar || month == May || month == Jul || month == Aug || month == Oct || month == Dec) {
		num_days = 31;
	} else if (month == Apr || month == Jun || month == Sep || month == Nov) {
		num_days = 30;
	} else if (month == Feb && year % 4 == 0) {
		num_days = 29;
	} else {
		num_days = 28;
	}

	int rows = ((num_days + first) / 7) + 2;

	int day = 1;
	cal = new(int* [rows]);
	for(int i = 0; i < rows; i++) {
		cal[i] = new int[7];
	}
	


	int idx = 0;
	while (day <= num_days) {
		if (idx == 0) {
			for (int i = 0; i < first; i++) {
				cal[idx][i] = 0;
			}

			for (int i = first; i < 7; i++) {
				cal[idx][i] = day++;
			}
		} else {
			for (int i = 0; i < 7; i++) {
				if (day <= num_days) {
					cal[idx][i] = day++;
				}	
			}
		}
		idx++;

	}
	cal[idx] = nullptr;
}

void Calandar::print() {
	string m;
	switch(month) {
		case Jan:
		m = "January";
		break;
		case Feb:
		m = "February";
		break;
		case Mar:
		m = "March";
		break;
		case Apr:
		m = "April";
		break;
		case May:
		m = "May";
		break;
		case Jun:
		m = "June";
		break;
		case Jul:
		m = "July";
		break;
		case Aug:
		m = "August";
		break;
		case Sep:
		m = "September";
		break;
		case Oct:
		m = "October";
		break;
		case Nov:
		m = "November";
		break;
		case Dec:
		m = "December";
		break;
	}
	
	cout << "   " << m << " " << year << endl;
	cout << "Su Mo Tu We Th Fr Sa " << endl;

	for (int i = 0; cal[i] != nullptr; i++) {
		for (int j = 0; j < 7; j++) {
			int x = cal[i][j];
			if (x == 0) {
				cout << "   ";
			} else if (x < 10) {
				cout << " " << x << " ";
			} else {
				cout << x << " ";
			}
		}
		cout << endl;
	}
}

int** Calandar::get() {
	return cal;
}

