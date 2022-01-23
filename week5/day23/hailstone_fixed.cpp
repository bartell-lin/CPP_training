#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <algorithm>


using namespace std;
void hailstone(vector<int>& hail);
mutex m;

int main() {
	vector<int> hail = {11};

	thread t1(hailstone, ref(hail));
	thread t2(hailstone, ref(hail));
	t1.join();
	t2.join();

	cout << "Hailstone sequence" << endl;
	for (int i: hail) {
		cout << i << endl;
	}
}

void hailstone(vector<int>& hail) {
	int n = hail.back();
	while(n = hail.back(), n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			if (m.try_lock()) {
				if (hail.back() != n) {
					hail.push_back(n);
				}
				m.unlock();
			}
		} else {
			n = (3 * n) + 1;
			if (m.try_lock()) {
				if (hail.back() != n) {
					hail.push_back(n);
				}
				m.unlock();
			}
		}
	}
}

