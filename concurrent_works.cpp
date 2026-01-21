#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

constexpr long long N = 500000000;

long long sum_range(long long start, long long end) {
    long long sum = 0;
    for (long long i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    // Single-threaded
    auto t1 = std::chrono::high_resolution_clock::now();
    long long single_sum = sum_range(1, N);
    auto t2 = std::chrono::high_resolution_clock::now();

    // -> cast nanosecond duration to millisecond
    // -> count() return long
    auto single_time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Single-threaded sum: " << single_sum << " in " << single_time << "ms" << std::endl;


    // Multi-threaded (5 threads)
    std::vector<std::thread> threads;
    std::vector<long long> results(5);

    // 1 0000 0000
    long long chunk = N / 5;

    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 5; ++i) {
        long long start = i * chunk + 1;
        long long end = (i == 4) ? N : (i + 1) * chunk;
        threads.emplace_back([&results, i, start, end]() {
            results[i] = sum_range(start, end);
        });
    }
    for (auto& t : threads) {
        t.join();
    }
    long long multi_sum = 0;
    for (auto r : results) {
        multi_sum += r;
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto multi_time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Multi-threaded sum: " << multi_sum << " in " << multi_time << "ms" << std::endl;

    std::cout << "Speedup: " << (double)single_time / multi_time << "x" << std::endl;
}