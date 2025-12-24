#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long fib(long long n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    auto start = high_resolution_clock::now();
    const int TIME_LIMIT_MS = 2000; 

    long long count = 0;
    long long n = 10; 

    while (true) {
        fib(n);
        count++;

        auto now = high_resolution_clock::now();
        auto elapsed =
            duration_cast<milliseconds>(now - start).count();

        if (elapsed >= TIME_LIMIT_MS)
            break;
    }

    cout << "Computed fib(" << n << ") "
         << count << " times in "
         << TIME_LIMIT_MS << " ms\n";
}
