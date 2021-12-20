#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <sstream>
#include "assert.h"
#include "bank_account.pb.h"

using namespace std;

vector<string> split(string s);
void new_account(istream& s1, istream& s2);
void close_account(istream& s1, istream& s2);

BankAccount::Bank bank;
int counter = 101;

int main() {
  string s = "john doe";
  vector<string> v = split(s);
  assert(v[0] == "john");
  assert(v[1] == "doe");

  istringstream input1("john doe");
  istringstream input2("123456789");
  new_account(input1, input2);
  assert(bank.accounts_size() == 1);
  assert(bank.accounts(0).ssn() == "123456789");


  istringstream name2("mary jane");
  istringstream ssn2("123456788");
  new_account(name2, ssn2);
  assert(bank.accounts_size() == 2);

  istringstream repname("mary jane");
  istringstream repssn("123456788");
  new_account(repname, repssn);
  assert(bank.accounts_size() == 2);


  istringstream input3("101");
  istringstream input4("yes");
  close_account(input3, input4);
  assert(bank.accounts_size() == 1);

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


void new_account(istream& s1, istream& s2) {
  string name;
  string ssn;
  s1 >> name;
  s2 >> ssn;

  for (int i = 0; i < bank.accounts_size(); i++) {
    const BankAccount::bankAccount& account = bank.accounts(i);
    if (account.name() == name || account.ssn() == ssn) {
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


void close_account(istream& s1, istream& s2) {
  string acc_num;
  s1 >> acc_num;


  for (int i = 0; i < bank.accounts_size(); i++) {
    const BankAccount::bankAccount& account = bank.accounts(i);
    if (account.account_num() == acc_num) {
      string confirm;
      s2 >> confirm;
      if (confirm == "yes") {
        bank.mutable_accounts()->DeleteSubrange(i, 1);
        return;
      } else {
        return;
      }
    }
  }

  cout << "This account doesn't exist" << endl;
}
