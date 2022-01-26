#include <vector>
#include <thread>
#include <numeric>
#include <iostream>
#include <future>
#include <chrono>
#include <cassert>


template<typename Iterator, typename T> struct accumulate_block {
	void operator() (Iterator first, Iterator last, T& result) {
		result = std::accumulate(first, last, result);
	}
};

void parallel_accumulate(std::vector<long>::iterator first, std::vector<long>::iterator last, long init, std::promise<long> accumulate_promise) {
	unsigned long const length = std::distance(first, last);
	if (!length) {
		accumulate_promise.set_value(init);
	}
	unsigned long const min_per_thread = 25;
	unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
	unsigned long const hardware_threads = std::thread::hardware_concurrency();
	unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads: 2, max_threads);

	unsigned long const block_size = length/num_threads;
	std::vector<long> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);
	std::vector<long>::iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); ++i) {
		std::vector<long>::iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(accumulate_block<std::vector<long>::iterator, long>(), block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}
	accumulate_block<std::vector<long>::iterator, long>() (block_start, last, results[num_threads - 1]);
	for (auto& entry: threads) {
		entry.join();
	}

	long sum = std::accumulate(results.begin(), results.end(), init);
	accumulate_promise.set_value(sum);
}


int main() {
	constexpr long LEN = 20000;
	std::vector<long> myvec;
	for (long i = 0; i < LEN; i++) {
		myvec.push_back(i);
	}
	std::promise<long> accumulate_promise;
	std::future<long> accumulate_future = accumulate_promise.get_future();
	std::thread work_thread(parallel_accumulate, myvec.begin(), myvec.end(), 0, std::move(accumulate_promise));


	assert(accumulate_future.get() == 199990000);
	work_thread.join();
	

}