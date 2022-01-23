#include <thread>
#include <iostream>
#include <vector>

using namespace std;
void hailstone(int n, vector<int>& hail);

int main() {
	vector<int> hail;

	thread t1(hailstone, 11, ref(hail));
	thread t2(hailstone, 11, ref(hail));
	t1.join();
	t2.join();

	for (int i: hail) {
		cout << i << endl;
	}
}

void hailstone(int n, vector<int>& hail) {
	hail.push_back(n);

	while(n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			hail.push_back(n);
		} else {
			n = (3 * n) + 1;
			hail.push_back(n);
		}
	}
}

