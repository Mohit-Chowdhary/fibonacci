#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long fib(long long n) {
    long long a = 0; // F(0)
    long long b = 1; // F(1)

    // iterate from highest bit to lowest bit
    for (int i = 63 - __builtin_clzll(n); i >= 0; --i) {
        long long d = a * (2 * b - a); // F(2k)
        long long e = a * a + b * b;   // F(2k+1)

        if ((n >> i) & 1) {
            a = e;
            b = d + e;
        } else {
            a = d;
            b = e;
        }
    }
    return a;
}

int main() {
    auto start = high_resolution_clock::now();
    const int TIME_LIMIT_MS = 2000;

    long long count = 0;
    long long n = 30;

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
