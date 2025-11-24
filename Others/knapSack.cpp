#include <iostream>
#include <vector>
#include <algorithm>

// 0/1 knapsack: max value with capacity W
int knapSack(int W,
             std::vector<int> const &wt,
             std::vector<int> const &val
) {
    int n = static_cast<int>(std::size(wt));
    std::vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= wt[i]; --w) { // go backwards
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    std::vector<int> wt { 2, 3, 4, 5 };
    std::vector<int> val { 3, 4, 5, 6 };
    int W = 5;
    int answer = knapSack(W, wt, val);
    std::cout << "Knapsack W =" << W << " -> max value = " << answer << "\n";
    // Expected output: 7 ((2, 3) and (3, 4))
}
