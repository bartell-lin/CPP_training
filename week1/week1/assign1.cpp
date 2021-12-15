#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include "assign1.h"

using namespace std;


struct bank {
	string name;
	string account_num;
	string ssn;
	string date_opened;
};

vector<bank> bank_accounts;
int counter = 101;

int main() {
	string username;
	string password;
	ifstream inputFile("./password.txt");
	if (inputFile.is_open()) {
		getline(inputFile, username);
		getline(inputFile, password);
		inputFile.close();
	}

	while (true) {
		cout << "Admin Login" << endl;
		string user;
		cout << "user: ";
		getline(cin, user);
		string pass;
		cout << "password: ";
		getline(cin, pass);

		if (user == username && pass == password) {
			break;
		} else {
			cout << "Incorrect User" << endl;
		}
	}


	while(true) {
		string input;
		cout << "home > ";
		getline(cin, input);

		if (input == "show accounts") {
			show_accounts();

		} else if (input == "display account") {
			display_account();

		} else if (input == "search name") {
			search_name();

		} else if (input == "new account") {
			new_account();

		} else if (input == "close account") {
			close_account();

		} else if (input == "quit") {
			return 0;
		} else {
			cout << "Invalid Input" << endl;
		}
	}
	
}


void show_accounts() {
	for (auto i: bank_accounts) {
		cout << i.name << " " << i.account_num << " " << i.date_opened << endl;
	}
}

void display_account() {
	string acc_num;
	cout << "Enter account number: ";
	getline(cin, acc_num);
	for (auto i: bank_accounts) {
		if (i.account_num == acc_num) {
			cout << i.name << " " << i.ssn.substr(5, 9) << " " << i.date_opened << " " << acc_num << endl;
			return;
		}
	}
	cout << "Invalid account" << endl;
}

void search_name() {
	string name;
	cout << "Enter Name: ";
	getline(cin, name);

	vector<bank> search;
	vector<string> firstlast = split(name);
	for (auto i: bank_accounts) {
		vector<string> temp = split(i.name);
		if (i.name == name) {
			search.insert(search.begin(), i);
		} else if (temp[0] == firstlast[0] || temp[1] == firstlast[1]) {
			search.push_back(i);
		}
	}

	int i;
	for (i = 0; i < search.size(); i++) {
		cout << i+1 << ". " << search[i].name << endl;
	}
	cout << i+1 << ". Home" << endl;
	cout << "Select number: ";
	string input;
	cin >> input;

	//Incomplete logic. can be fixed
	if (input == "1") {
		cout << search[0].name << " " << search[0].ssn.substr(5, 9) << " " << search[0].date_opened << " " << search[0].account_num << endl;
	} else if (input == "2") {
		if (i > 2) {
			cout << search[1].name << " " << search[1].ssn.substr(5, 9) << " " << search[1].date_opened << " " << search[1].account_num << endl;
		}
	} else if (input == "3") {
		if (i > 3) {
			cout << search[2].name << " " << search[2].ssn.substr(5, 9) << " " << search[2].date_opened << " " << search[2].account_num << endl;
		}
	} else if (input == "4") {
		return;
	} else {
		cout << "Invalid number" << endl;
		search_name();
	}
}

vector<string> split(string s) {
	stringstream ss(s);
	string word;
	vector<string> ret;
	while (ss >> word) {
		ret.push_back(word);
	}
	return ret;
}


void new_account() {
	string name;
	string ssn;
	cout << "Enter customer name : ";
	getline(cin, name);
	cout << "Enter customer ssn : ";
	getline(cin, ssn);
	if (ssn.length() != 9) {
		cout << "Invalid SSN" << endl;
		return;
	}


	for (auto i: bank_accounts) {
		if (i.name == name || i.ssn == ssn) {
			cout << "Account exists" << endl;
			return;
		}
	}
	bank b;
	b.name =  name;
	b.ssn = ssn;
	b.account_num = to_string(counter++);

	time_t now = time(0);
	tm* dt = localtime(&now);
	b.date_opened = to_string(dt->tm_mon) + "/" + to_string(dt->tm_mday) + "/" + to_string(1900 + dt->tm_year);

	bank_accounts.push_back(b);

}

void close_account() {
	string acc_num;
	cout << "Enter account number: ";
	cin >> acc_num;

	for (int i = 0; i < bank_accounts.size(); i++) {
		if (bank_accounts[i].account_num == acc_num) {
			string confirm;
			cout << "Are you sure? [yes/no] ";
			cin >> confirm;
			if (confirm == "yes") {
				bank_accounts.erase(bank_accounts.begin() + i);
				cout << "Account Closed" << endl;
				return;
			} else {
				cout << "Action canceled" << endl;
				return;
			}
		}
	}
	cout << "This account doesn't exist" << endl;
}

















