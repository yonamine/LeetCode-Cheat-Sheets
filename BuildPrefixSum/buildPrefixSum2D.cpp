#include <iostream>
#include <vector>

std::vector<std::vector<int>> buildPrefixSum2D(std::vector<std::vector<int>> const &grid) {
    int n = std::size(grid);
    int m = std::size(grid[0]);

    // Add one extra (row, column) to prefix
    std::vector<std::vector<int>> prefix(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }
    return prefix;
}

// Query sum for submatrix [r1..r2][c1..c2]
int submatrixSum(std::vector<std::vector<int>> const &prefix,
                 int r1, int c1,
                 int r2, int c2) {
    return prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - prefix[r2 + 1][c1] + prefix[r1][c1];
}

int main() {
    std::vector<std::vector<int>> grid {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };

    auto prefix = buildPrefixSum2D(grid);
    std::cout << "Sum of submatrix [(0,0)..(1,1)] = " << submatrixSum(prefix, 0, 0, 1, 1) << '\n'; // 1 + 2 + 4 + 5
    // Sum of submatrix [(0,0)..(1,1)] = 12
    std::cout << "Sum of submatrix [(1,1)..(2,2)] = " << submatrixSum(prefix, 1, 1, 2, 2) << '\n'; // 5 + 6 + 8 + 9
    // Sum of submatrix [(1,1)..(2,2)] = 28
    std::cout << "Sum of submatrix [(0,1)..(2,2)] = " << submatrixSum(prefix, 0, 1, 2, 2) << '\n'; // 2 + 3 + 5 + 6 + 8 + 9
    // Sum of submatrix [(0,1)..(2,2)] = 33
}
