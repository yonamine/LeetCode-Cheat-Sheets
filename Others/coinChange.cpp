#include <limits>
#include <iostream>
#include <vector>

constexpr int kInfinite = std::numeric_limits<int>::max() / 2;

// Minimum coins to make 'amount', or -1 if impossible
int coinChange(std::vector<int> const &coins, int amount) {
    std::vector<int> dp(amount + 1, kInfinite);

    dp[0] = 0;

    for (auto coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
    }

    return (dp[amount] == kInfinite) ? -1 : dp[amount];
}

int main() {
    std::vector<int> coins { 1, 2, 5 };
    int amount = 11;
    int answer = coinChange(coins, amount);
    std::cout << "Coin change, amount = " << amount << " -> " << answer << '\n';
    // Expected output: 3 (11 = 5 + 5 + 1)
}
