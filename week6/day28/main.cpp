#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>


enum myenum {debit, credit};


struct transaction {
  	long post_date; // post date of transaction
  	std::string src_accountId;  // use UUIDs
  	std::string dest_accountId;  // use UUIDs
  	myenum tranType; // transaction type enum can be credit or debit
  	double amount; // in dollars ranging [1..1000000]
};


template<typename T>
struct Generator {
  struct promise_type;
  using handle_type = std::coroutine_handle<promise_type>;

  struct promise_type {
    T value_;
    std::exception_ptr exception_;

    Generator get_return_object() {
      return Generator(handle_type::from_promise(*this));
    }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() { exception_ = std::current_exception(); }
    template<std::convertible_to<T> From> 
    std::suspend_always yield_value(From &&from) {
      value_ = std::forward<From>(from);
      return {};
    }
    void return_void() {}
  };

  handle_type h_;

  Generator(handle_type h) : h_(h) {}
  ~Generator() { h_.destroy(); }
  explicit operator bool() {
    fill();
    return !h_.done();
  }
  T operator()() {
    fill();
    full_ = false;
    return std::move(h_.promise().value_);
  }

private:
  bool full_ = false;

  void fill() {
    if (!full_) {
      h_();
      if (h_.promise().exception_)
        std::rethrow_exception(h_.promise().exception_);
      full_ = true;
    }
  }
};

Generator<struct transaction> transact() {
  for (unsigned i = 0; i < 20; i++) {
  	int date = rand() % 30 + 20220101;
  	std::string src = std::to_string(rand() % 99999 + 10000);
  	std::string dest = std::to_string(rand() % 99999 + 10000);
  	double amt = rand() % 1000000 + (rand() % 100)/ 100.0;
  	myenum dc = (rand() % 2) == 0 ? myenum::debit : myenum::credit;
  	struct transaction t = {date, src, dest, dc, amt};
  	co_yield t;
  }
}

int main(void) {
  auto gen = transact();
  for (int i = 0; i < 20; i++) {
  	auto val = gen();
  	std::string s = val.tranType == 0 ? "debit" : "credit";
    std::cout << "date: " << val.post_date << std::endl;
    std::cout << "from: " << val.src_accountId << std::endl;
    std::cout << "to: " << val.dest_accountId << std::endl;
    std::cout << "type: " << s << std::endl;
    std::cout << "amount: " << val.amount << std::endl;
    std::cout << std::endl;
  }
}

