#include <atomic>
#include <future>
#include <vector>
#include <iterator>
#include <cassert>
#include <iostream>

template<typename Iterator,typename MatchType>
Iterator parallel_none_impl(Iterator first, Iterator last, MatchType match, std::atomic<bool>& done) {
    try {
        unsigned long const length = std::distance(first, last);
        unsigned long const min_per_thread = 25;
        if (length < (2 * min_per_thread)) {
            for (;(first != last) && !done.load(); ++first) {
                if (match(*first)) {
                    done = true;
                    return first;
                }
            }
            return last;
        } else {
            Iterator const mid_point = first + (length / 2);
            std::future<Iterator> async_result = std::async(&parallel_none_impl<Iterator,MatchType>, mid_point, last, match, std::ref(done));
            Iterator const direct_result = parallel_none_impl(first, mid_point, match, done);
            return (direct_result == mid_point)? async_result.get() : direct_result;
        }
    }
    catch(...) { done = true; throw; }
}

template<typename Iterator,typename MatchType>
bool parallel_none(Iterator first, Iterator last, MatchType match) {
    std::atomic<bool> done(false);
    auto any = parallel_none_impl(first, last, match, done);
    if (any == last) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    std::vector<int> myvec(10000, 0);

    std::vector<int>::iterator iter = myvec.begin();
    iter += 5000;
    myvec.insert(iter, 5);
    auto any = parallel_none(myvec.begin(), myvec.end(), [](int i){return i > 0;});
    assert(any == false);
    
    auto none = parallel_none(myvec.begin(), myvec.end(), [](int i){return i < 0;});
    assert(none == true);
}

