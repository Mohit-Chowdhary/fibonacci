#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long fib(long long n) {
    long long a = 0, b = 1;
    for (long long i = 0; i < n; i++) {
        long long c = a + b;
        a = b;
        b = c;
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
