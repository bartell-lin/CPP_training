#include <thread>
#include <iostream>
#include <algorithm>
#include <mutex>
#include <string>

using namespace std;
class Country {
public:
	double dollars;
	double pounds;
	mutex m;
	Country(double d, double p): dollars(d), pounds(p) {}
};

void request(double rate, double amt, string currency, Country& current, Country& other);
void buy_dollar(double rate, double amt, Country& current, Country& other);
void buy_pound(double rate, double amt, Country& current, Country& other);
void loop(Country& c1, Country& c2);


int main() {
	Country c1(500, 1000);
	Country c2(2000, 1000);

	thread t1(loop, ref(c1), ref(c2));
	thread t2(loop, ref(c2), ref(c1));

	t1.join();
	t2.join();

}

void loop(Country& c1, Country& c2) {
	for (int i = 0; i < 1000; i++) {
		request(1.36, 10, "Dollar", ref(c1), ref(c2));
		request(.74, 10, "Pound", ref(c1), ref(c2));
	}
}


void request(double rate, double amt, string currency, Country& current, Country& other) {
	if (currency == "Dollar") {
		buy_dollar(rate, amt, current, other);
	} else if (currency == "Pound") {
		buy_pound(rate, amt, current, other);
	}
}

void buy_dollar(double rate, double amt, Country& current, Country& other) {
	if ((current.pounds > amt * rate) && (other.dollars > amt)) {
		current.m.lock();
		other.m.lock();
		current.dollars += amt;
		current.pounds -= amt * rate;
		other.dollars -= amt;
		other.pounds += amt * rate;
		other.m.unlock();
		current.m.unlock();
	}

}
void buy_pound(double rate, double amt, Country& current, Country& other) {
	if ((current.dollars > amt * rate) && (other.pounds > amt)) {
		current.m.lock();
		other.m.lock();
		current.pounds += amt;
		current.dollars -= amt * rate;
		other.pounds -= amt;
		other.dollars += amt * rate;
		other.m.unlock();
		current.m.unlock();
	}

}





