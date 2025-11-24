#include <iostream>

// DP kind of Fibonacci - Basic DP (iterative)
int climbStairs(int n) {
    if (n <= 1) {
        return 1;
    }

    int prev2 = 1; // f(0)
    int prev1 = 1; // f(1)
    for (auto i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n = 5;
    int ways = climbStairs(n);
    std::cout << "Climb Stairs n = " << n << " -> " << ways << '\n';
    // Expected output: 8 (Fibonacci sequence)
}
