#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;
vector<string> split(string s);
void new_account(istream& s1, istream& s2);
void close_account(istream& s1, istream& s2);


struct bank {
  string name;
  string account_num;
  string ssn;
  string date_opened;
};
vector<bank> bank_accounts;
int counter = 101;



TEST(SplitTest, test1) {

  string s = "john doe";
  vector<string> v = split(s);
  ASSERT_TRUE(v[0] == "john");
  ASSERT_TRUE(v[1] == "doe");

}


TEST(AccountTest, test2) {
  istringstream input1("john doe");
  istringstream input2("123456789");
  new_account(input1, input2);
  ASSERT_TRUE(bank_accounts.size() == 1);

}

TEST(CloseTest, test3) {
  istringstream name1("john doe");
  istringstream ssn1("123456789");
  new_account(name1, ssn1);
  ASSERT_TRUE(bank_accounts.size() == 1);

  istringstream name2("mary jane");
  istringstream ssn2("123456788");
  new_account(name2, ssn2);
  ASSERT_TRUE(bank_accounts.size() == 2);


  istringstream input3("101");
  istringstream input4("yes");
  close_account(input3, input4);
  ASSERT_TRUE(bank_accounts.size() == 1);

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

  for (auto i: bank_accounts) {
    if (i.name == name || i.ssn == ssn) {
      cout << "Account exists" << endl;
      return;
    }
  }
  bank b;
  b.name = name;
  b.ssn = ssn;
  b.account_num = to_string(counter++);

  time_t now = time(0);
  tm* dt = localtime(&now);
  b.date_opened = to_string(dt->tm_mon) + "/" + to_string(dt->tm_mday) + "/" + to_string(1900 + dt->tm_year);

  bank_accounts.push_back(b);

}


void close_account(istream& s1, istream& s2) {
  string acc_num;
  s1 >> acc_num;

  for (int i = 0; i < bank_accounts.size(); i++) {
    if (bank_accounts[i].account_num == acc_num) {
      string confirm;
      s2 >> confirm;
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