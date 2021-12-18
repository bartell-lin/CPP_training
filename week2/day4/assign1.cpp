#include <iostream>
#include <map>

using namespace std;

class Grade {
	map<char, int> m {{10, 'D'}, {20, 'C'}, {30, 'B'}, {40, 'A'}};
	public:
		char grade(const int&& score) {
			return m[score];
		}
};


int main() {
	Grade g;
	int scores[4] = {10, 20, 30, 40};
	for (int i = 0; i < 4; i++) {
		cout << "Score = " << scores[i] << ": Grade " << g.grade(move(scores[i])) << endl;
	}

}