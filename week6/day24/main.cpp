#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>
#include <cassert>
#include "safeq.h"



struct data_chunk { int x; };
threadsafe_queue<data_chunk> data_queue;
int total;

void create_q() {
    for (int i = 0; i < 10; i++) {
        data_chunk data = { i };
        std::cerr << "Pushing: " << data.x << std::endl;
        data_queue.push(data);
    }
}

void pop_q() {
    while (true) {
        data_chunk data;
        if (data_queue.try_pop(data)) {
            std::cerr << "Popping: " << data.x << std::endl;
            total += data.x;
        }
        if (data.x == 9) {
            break;
        }
    }
}

void sum_q() {
    while (true) {
        std::shared_ptr<data_chunk> data = data_queue.try_pop();
        std::cerr << "Popping: " << data->x << std::endl;
        total += data->x;
        if (data->x == 9) {
            break;
        }
    }
}


int main() {
    std::thread t1(create_q);
    std::thread t2(pop_q);
    
    t1.join();
    t2.join();

    assert(total == 45);
    total = 0;

    std::thread t3(create_q);
    t3.join();
    std::thread t4(sum_q);
    t4.join();

    assert(total == 45);

}