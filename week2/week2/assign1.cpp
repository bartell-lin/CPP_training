#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include "bank_account.pb.h"
#include "assign1.h"

using namespace std;



BankAccount::Bank bank;
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
	stringstream geek(password);
	size_t hpass;
	geek >> hpass;

	int x = 3;
	while (true) {
		x--;
		if (x < 0) {
			return 0;
		}
		cout << "Admin Login" << endl;
		string user;
		cout << "user: ";
		getline(cin, user);
		string pass;
		cout << "password: ";
		getline(cin, pass);

		// use hash to encrypt password but not the same on every computer
		hash<string> str_hash;
		size_t verify = str_hash(pass);


		if (user == username && verify == hpass) {
			break;
		} else {
			cout << "Incorrect User" << endl;
		}
	}

	{
		fstream output("binary", ios::out | ios::trunc | ios::binary);
    	fstream input("binary", ios::in | ios::binary);
    		if (!bank.ParseFromIstream(&input)) {
     			cerr << "Failed to parse bank." << endl;
      			return -1;
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

		} else if (input == "") {
			;

		} else if (input == "help") {
			cout << "Try these commands" << endl;
			cout << "show accounts" << endl;
			cout << "display account" << endl;
			cout << "search name" << endl;
			cout << "new account" << endl;
			cout << "close account" << endl;
			cout << "quit" << endl;

		} else if (input == "quit") {
			{
    			fstream output("binary", ios::out | ios::trunc | ios::binary);
    				if (!bank.SerializeToOstream(&output)) {
      					cerr << "Failed to write bank." << endl;
      					return -1;
    				}
  			}
			return 0;
		} else {
			cout << "Invalid Input" << endl;
		}
	}
	
}


void show_accounts() {
	for (int i = 0; i < bank.accounts_size(); i++) {
		const BankAccount::bankAccount& account = bank.accounts(i);
		cout << account.name() << " " << account.account_num() << " " << account.date_opened() << endl;
	}
}

void display_account() {
	string acc_num;
	cout << "Enter account number: ";
	getline(cin, acc_num);

	for (int i = 0; i < bank.accounts_size(); i++) {
		BankAccount::bankAccount* account = bank.mutable_accounts(i);
		if (account->account_num() == acc_num) {
			cout << account->name() << " " << account->ssn().substr(5, 9) << " " << account->date_opened() << " " << acc_num << endl;
			add_transaction(account);
			return;
		}
	}
	cout << "Invalid account" << endl;
}

void add_transaction(BankAccount::bankAccount* account) {
	string next;
	cout << "Make 'transaction' or return 'home'" << endl;
	cin >> next;
	if (next == "home") {
		return;
	} else {
		string amount;
		cout << "Enter amount" << endl;
		cin >> amount;
		string card;
		cout << "debit/credit" << endl;
		cin >> card;

		string::size_type sz;
		int money = std::stoi (amount, &sz);



		if (card == "debit") {
			if (account->balance() < money) {
				cout << "Insufficient Balance" << endl;
				return;
			}
		}
		account->set_balance(account->balance() - money);

		cout << "Your balance is now " << account->balance() << endl;
		add_transaction(account);
	}

}

void search_name() {
	string name;
	cout << "Enter Name: ";
	getline(cin, name);

	vector<BankAccount::bankAccount> search;
	vector<string> firstlast = split(name);

	for (int i = 0; i < bank.accounts_size(); i++) {
		const BankAccount::bankAccount& account = bank.accounts(i);
		vector<string> temp = split(account.name());
		if (account.name() == name) {
			search.insert(search.begin(), account);
		} else if (temp[0] == firstlast[0] || temp[1] == firstlast[1]) {
			search.push_back(account);
		}
	}

	int i;
	for (i = 0; i < search.size(); i++) {
		cout << i+1 << ". " << search[i].name() << endl;
	}
	cout << i+1 << ". Home" << endl;
	cout << "Select number: ";
	string input;
	cin >> input;

	string::size_type sz;
	int i_dec = std::stoi (input, &sz);
	if (i_dec == i + 1) {
		return;
	} else if (i_dec > 0 && i_dec <= search.size()) {
		cout << search[i_dec - 1].name() << " " << search[i_dec - 1].ssn().substr(5, 9) << " " << search[i_dec - 1].date_opened() << " " << search[i_dec - 1].account_num() << endl;
	} else {
		cout << "Invalid number" << endl;
		return;
		//search_name();
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

	for (int i = 0; i < bank.accounts_size(); i++) {
		const BankAccount::bankAccount& account = bank.accounts(i);
		if (account.name() == name || account.ssn() == ssn) {
			cout << "Account exists" << endl;
			return;
		}

	}

	BankAccount::bankAccount* account = bank.add_accounts();
	account->set_name(name);
	account->set_ssn(ssn);
	account->set_account_num(to_string(counter++));
	account->set_balance(200);

	time_t now = time(0);
	tm* dt = localtime(&now);
	string date = to_string(dt->tm_mon) + "/" + to_string(dt->tm_mday) + "/" + to_string(1900 + dt->tm_year);

	account->set_date_opened(date);
}

void close_account() {
	string acc_num;
	cout << "Enter account number: ";
	cin >> acc_num;


	for (int i = 0; i < bank.accounts_size(); i++) {
		const BankAccount::bankAccount& account = bank.accounts(i);
		if (account.account_num() == acc_num) {
			string confirm;
			cout << "Are you sure? [yes/no] ";
			cin >> confirm;
			if (confirm == "yes") {
				bank.mutable_accounts()->DeleteSubrange(i, 1);
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

















