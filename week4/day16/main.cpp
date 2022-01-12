#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>
using namespace std;

bool checkhex(const string& s);
bool checkdec(const string& s);
bool checkbin(const string& s);



int main() {
	while(true) {
		cout << "prompt > ";
		string inp;
		getline(cin, inp);
		istringstream iss(inp);
		string word;
		vector<string> v;

		while (iss >> word) {
			v.push_back(word);
		}

		if (v.size() == 1) {
			if (v[0] == "quit" || v[0] == "exit") {
				break;

			} else if (checkhex(v[0])) {
				int num = std::stoi(v[0].substr(2), nullptr, 16);
				cout << "prompt > " << num << endl;

			} else if (checkbin(v[0])) {
				int num = std::stoi(v[0].substr(2), nullptr, 2);
				cout << "prompt > " << num << endl;
			}

		} else if (v.size() == 2) {
			if (v[0] == "bin") {
				if (checkdec(v[1])) {
					string::size_type sz;
    				int num = std::stoi(v[1], &sz);
					cout << "prompt > " << "0b" << bitset<16>(num) << endl;
				} else if (checkhex(v[1])) {
    				int num = std::stoi(v[1].substr(2), nullptr, 16);
					cout << "prompt > " << "0b" << bitset<16>(num) << endl;
				} else {
					cout << "Invalid Input" << endl;
				}

			} else if (v[0] == "hex") {
				if (checkdec(v[1])) {
					string::size_type sz;
    				int num = std::stoi(v[1], &sz);
					cout << "prompt > " << "0x" << hex << num << endl;
				} else if (checkbin(v[1])) {
    				int num = std::stoi(v[1].substr(2), nullptr, 2);
					cout << "prompt > " << "0x" << hex << num << endl;
				} else {
					cout << "Invalid Input" << endl;
				}

			} else {
				cout << "Invalid Input" << endl;
			}
		
		} else if (v.size() == 3) {
			if (v[1] == "+") {
				int sum = 0;
				if (checkdec(v[0])) {
					string::size_type sz;
    				int num = std::stoi(v[0], &sz);
					sum += num;
				} else if (checkhex(v[0])) {
    				int num = std::stoi(v[0].substr(2), nullptr, 16);
					sum += num;
				}  else if (checkbin(v[0])) {
    				int num = std::stoi(v[0].substr(2), nullptr, 2);
					sum += num;
				} else {
					cout << "Invalid Input" << endl;
				}

				if (checkdec(v[2])) {
					string::size_type sz;
    				int num = std::stoi(v[2], &sz);
					sum += num;
				} else if (checkhex(v[2])) {
    				int num = std::stoi(v[2].substr(2), nullptr, 16);
					sum += num;
				} else if (checkbin(v[2])) {
    				int num = std::stoi(v[2].substr(2), nullptr, 2);
					sum += num;
				} else {
					cout << "Invalid Input" << endl;
				}

				cout << "prompt > " << sum << endl;
			} else {
				cout << "Invalid Input" << endl;
			}

		} else {
			cout << "Invalid Input" << endl;
		}
		
	}
}



bool checkhex(const string& s) {
	return s.compare(0, 2, "0x") == 0
      && s.size() > 2
      && s.find_first_not_of("0123456789abcdefABCDEF", 2) == string::npos;
}

bool checkdec(const string& s) {
	return s.find_first_not_of("0123456789", 0) == std::string::npos;
}

bool checkbin(const string& s) {
	return s.compare(0, 2, "0b") == 0
      && s.size() > 2
      && s.find_first_not_of("01", 2) == string::npos;
}