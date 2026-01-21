#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

struct Mat {
    long long a, b, c, d;
};

inline Mat multiply(const Mat& x, const Mat& y) {
    return {
        x.a * y.a + x.b * y.c,
        x.a * y.b + x.b * y.d,
        x.c * y.a + x.d * y.c,
        x.c * y.b + x.d * y.d
    };
}

Mat mat_pow(Mat base, long long exp) {
    Mat res = {1, 0, 0, 1}; // Identity

    while (exp > 0) {
        if (exp & 1)
            res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

long long fib(long long n) {
    if (n == 0) return 0;
    Mat fibMat = {1, 1, 1, 0};
    Mat res = mat_pow(fibMat, n - 1);
    return res.a; // F(n)
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
