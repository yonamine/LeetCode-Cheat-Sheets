#include <algorithm>
#include <limits>
#include <iostream>
#include <vector>

int minPathSum(std::vector<std::vector<int>> &grid) {
    int n = static_cast<int>(std::size(grid));
    int m = static_cast<int>(std::size(grid[0]));

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    std::vector<std::vector<int>> grid {
        { 1, 3, 1 },
        { 1, 5, 1 },
        { 4, 2, 1 },
    };

    int answer = minPathSum(grid);
    std::cout << "Minimum path sum = " << answer << "\n";
    // Expected output: 7 (1 -> 3 -> 1 -> 1 -> 1)
}
