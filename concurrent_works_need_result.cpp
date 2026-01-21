#include <chrono>
#include <future>
#include <iostream>

long long sum_range(long long start, long long end) {
    long long sum = 0;
    for (long long i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();

    std::future<long long> f1 = std::async(std::launch::async, sum_range, 1, 1000000);
    std::future<long long> f2 = std::async(std::launch::async, sum_range, 1000001, 2000000);

    long long result = f1.get() + f2.get();

    auto t2 = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    std::cout << "Result: " << result << " in " << elapsed << "ms" << std::endl;
}
