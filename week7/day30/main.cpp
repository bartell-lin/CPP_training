#include <thread>
#include <assert.h>
#include <iostream>
#include <vector>
#include <atomic>
#include <numeric>
#include <future>
#include <iterator>
#include <memory>
#include <functional>
#include "safeq.h"
#include "wrapper.h"


struct join_threads {
    join_threads(std::vector<std::thread>& threads) 
    {}
};

template<class Iterator, class T>
struct accumulate_block{
  void operator()(Iterator first, Iterator last, std::promise<T> result){
    result.set_value(std::accumulate(first, last, 0));
  }
};

class thread_pool {
    std::atomic_bool done;
    threadsafe_queue<std::function<void()>> work_queue;
    std::vector<std::thread> threads;
    join_threads joiner;

    void worker_thread() {
        while(!done) {
            std::function<void()> task;
            if(work_queue.try_pop(task)) {
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }
public:
    thread_pool(): done(false), joiner(threads) {
        unsigned const thread_count=std::thread::hardware_concurrency();
        try {
            for(unsigned i=0;i<thread_count;++i) {
                threads.push_back(
                    std::thread(&thread_pool::worker_thread,this));
            }
        } catch(...) {
            done=true;
            throw;
        }
    }

    ~thread_pool() {
        done=true;
        for (auto& entry: threads) {
            entry.join();
        }
    }

    template<typename FunctionType>
    void submit(FunctionType f) {
        work_queue.push(std::function<void()>(f));
    }

};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {

    unsigned long const length = std::distance(first, last);

    if (!length)
        return init;

    unsigned long const block_size = 25;
    unsigned long const num_blocks = (length + block_size-1)/block_size;
    std::vector<std::future<T>> futures(num_blocks-1);
    std::vector<std::promise<T>> promises(num_blocks-1);

    thread_pool pool;
    Iterator block_start = first;

    for (unsigned long i = 0; i < (num_blocks-1); i++) {
        Iterator block_end = block_start;

        std::advance(block_end, block_size);

        futures[i] = promises[i].get_future();
        // pool.submit([&] {
        //       accumulate_block<Iterator,T>()(block_start, block_end, std::move(promises[i]));
        //     });
        [&] {
              accumulate_block<Iterator,T>()(block_start, block_end, std::move(promises[i]));
            }();
        block_start = block_end;
    }
    std::promise<T> prom;
    std::future<T> fut = prom.get_future();
    accumulate_block<Iterator,T>() (block_start,last, std::move(prom));

    T last_result = fut.get();
    T result = init;
    for (unsigned long i = 0; i < (num_blocks-1); ++i) {
        result += futures[i].get();
    }
    result += last_result;
    return result;
}

int main() {
	std::vector<int> myvec(1000, 1);
	int sum = parallel_accumulate<std::vector<int>::iterator, int>(myvec.begin(), myvec.end(), 0);

    assert(sum == 1000);
}
