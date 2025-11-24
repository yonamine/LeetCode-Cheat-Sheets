#include <iostream>
#include <utility>

// Basic iterative Fibonacci, 0-based: F(0)=0, F(1)=1
long long fib_iter(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 0;
    long long b = 1;

    for (int i = 2; i <= n; ++i) {
        long long c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Fast doubling: returns (F(n), F(n+1))
std::pair<long long, long long> fib_fast_doubling(long long n) {
    if (n == 0) {
        return { 0, 1 };
    }

    auto p = fib_fast_doubling(n / 2);

    long long a = p.first;              // F(k)
    long long b = p.second;             // F(k+1)
    long long c = a * (2 * b - a);      // F(2k)
    long long d = a * a + b * b;        // F(2k+1)

    if ((n % 2) == 0) {
        return { c, d };
    }

    return { d, c + d };
}

int main() {
    int n = 10;

    std::cout << "fib_iter(" << n << ") = " << fib_iter(n) << "\n";
    // Expected output: F(10) = 55

    auto fd = fib_fast_doubling(n);
    std::cout << "fib_fast_doubling(" << n << ") = " << fd.first << "\n";
    // Expected output: F(10) = 55
}
