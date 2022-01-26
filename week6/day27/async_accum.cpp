#include <vector>
#include <thread>
#include <numeric>
#include <iostream>
#include <future>
#include <algorithm>
#include <cassert>


void parallel_sum(std::vector<int>::iterator beg, std::vector<int>::iterator end, std::promise<int> accumulate_promise) {
	auto len = end - beg;
	if (len < 1000) {
		int total = std::accumulate(beg, end, 0);
		accumulate_promise.set_value(total);
	} else {
		std::vector<int>::iterator mid = beg + len/2;

		std::promise<int> p;
		std::shared_future<int> f = p.get_future();
		std::async(std::launch::async, parallel_sum, mid, end, std::move(p));

		std::promise<int> p2;
		std::shared_future<int> f2 = p2.get_future();
		parallel_sum(beg, mid, std::move(p2));

		int total = f.get() + f2.get();
		accumulate_promise.set_value(total);
	}

}


int main() {
	std::vector<int> v(3000, 1);

	std::promise<int> accumulate_promise;
	std::shared_future<int> accumulate_future = accumulate_promise.get_future();
	std::thread work_thread(parallel_sum, v.begin(), v.end(), std::move(accumulate_promise));

	assert(accumulate_future.get() == 3000);

	work_thread.join();
}