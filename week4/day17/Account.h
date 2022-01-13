#include <iostream>
#include <type_traits>
#include <cmath>
#include <limits>
using namespace std;


class Dollar {
public:
	float value;
	Dollar(float value): value(value) {};
};

class Euro {
public:
	float value;
	Euro(float value): value(value) {};
};

class Pound {
public:
	float value;
	Pound(float value): value(value) {};
};

class Yen {
public:
	float value;
	Yen(float value): value(value) {};
};


class Convert{
public:
	float operator()(Euro e);
	float operator()(Pound p);
	float operator()(Yen y);
	float operator()(Dollar d);
	float ret(Euro e);
	float ret(Pound p);
	float ret(Yen y);
	float ret(Dollar d);
};


template<class T>
class Account {
private:
	T amt;
public:
	Account(T t): amt(t) {
		if (!is_same_v<decltype(amt), Dollar>) {
			Convert c;
			amt.value = c(amt);
		}
	};
	~Account() = default;
	Account(const Account& other) = default;
	Account& operator=(const Account& other) {
		if (this == &other) return *this;
		amt.value = other.amt.value;
		return *this;
	}
	Account(Account&& other) = default;
	Account& operator=(Account&& other) {
		if (this == &other) return *this;
		amt = other.amt;
		other.amt.value = 0;
		return *this;
	}


	float get() {
		if (is_same_v<decltype(amt), Dollar>) {
			return amt.value;
		} else {
			Convert c;
			return c.ret(amt);
		}
	}

	float val() {
		return amt.value;
	}

	template<class Q>
	T deposit(float amount) {
		Q q(amount);
		if (is_same_v<decltype(q), Dollar>) {
			amt.value += q.value;
		} else {
			Convert c;
			amt.value += c(q);
		}
		return amt;
	}
	template<class Q>
	T withdraw(float amount) {
		Q q(amount);
		if (is_same_v<decltype(q), Dollar>) {
			amt.value -= q.value;
		} else {
			Convert c;
			amt.value -= c(q);
		}
		return amt;
	}

	template<class R>
	Account<R>* currency() {
		Account<R>* r = new Account<R>(amt.value);
		return r;
	}

	// operators
	template<class R>
	bool operator==(Account<R>& other) {
		return fabs(amt.value - other.val()) < numeric_limits<double>::epsilon();
	}
	bool operator!=(Account& other) {
		return fabs(amt.value - other.amt.value) >= numeric_limits<double>::epsilon();
	}
	bool operator>(Account& other) {
		return amt.value > other.amt.value;
	}
	bool operator<(Account& other) {
		return amt.value < other.amt.value;
	}
	float operator+(Account& other) {
		return amt.value + other.amt.value;
	}
	float operator-(Account& other) {
		return amt.value - other.amt.value;
	}
	float operator*(Account& other) {
		return amt.value * other.amt.value;
	}
	float operator/(Account& other) {
		return amt.value / other.amt.value;
	}
	void operator+=(Account& other) {
		amt.value += other.amt.value;
	}
	void operator-=(Account& other) {
		amt.value -= other.amt.value;
	}

	operator Dollar() const {
		if (is_same_v<decltype(amt), Dollar>) {
			return amt.value;
		} else {
			Dollar d(amt.value);
			return d;
		}
	}
	operator Euro() const {
		if (is_same_v<decltype(amt), Euro>) {
			return amt.value;
		} else {
			Euro e(amt.value);
			return e;
		}
	}
	operator Pound() const {
		if (is_same_v<decltype(amt), Pound>) {
			return amt.value;
		} else {
			Pound p(amt.value);
			return p;
		}
	}
	operator Yen() const {
		if (is_same_v<decltype(amt), Yen>) {
			return amt.value;
		} else {
			Yen y(amt.value);
			return y;
		}
	}

};
