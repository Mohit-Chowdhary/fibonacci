#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// returns {F(n), F(n+1)}
pair<long long, long long> fib_pair(long long n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib_pair(n >> 1); // a = F(k), b = F(k+1)

    long long c = a * (2 * b - a); // F(2k)
    long long d = a * a + b * b;   // F(2k+1)

    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

long long fib(long long n) {
    return fib_pair(n).first;
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
