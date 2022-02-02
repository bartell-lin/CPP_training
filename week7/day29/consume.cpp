#include <atomic>
#include <thread>
#include <assert.h>
#include <iostream>

std::atomic<int> x,y;
std::atomic<int> z;

void write_x() {
    x.store(1, std::memory_order_release);
}
void write_y() {
    y.store(2, std::memory_order_release);
}
void read_x_then_y() {
    while (!x.load(std::memory_order_consume));
    if (y.load(std::memory_order_consume))
        ++z;
}
void read_y_then_x() {
    while (!y.load(std::memory_order_consume));
    if (x.load(std::memory_order_consume))
        ++z;
}

int main() {
    int i = 0;
    while (++i < 100) {
        x = 0;
        y = 0;
        z = 0;
        std::thread a(write_x);
        std::thread b(write_y);
        std::thread c(read_x_then_y);
        std::thread d(read_y_then_x);
        a.join();
        b.join();
        c.join();
        d.join();
        assert((z.load() == 2) || (z.load() == 1));
    }
}