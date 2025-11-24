#include <iostream>
#include <queue>
#include <set>
#include <vector>

const std::vector<std::pair<int, int>> kDirections {
    {  1,  0 }, // top
    { -1,  0 }, // bottom
    {  0,  1 }, // right
    {  0, -1 }, // left
};

std::pair<int, int> operator+(std::pair<int, int> const &lhs, std::pair<int, int> const &rhs) {
    return { lhs.first + rhs.first, lhs.second + rhs.second };
}

bool isSafe(std::pair<int, int> position,
            std::vector<std::vector<int>> const &grid,
            std::vector<std::vector<int>> const &distances) {
    return (
        (position.first >= 0) && (position.first < std::size(grid)) &&
        (position.second >= 0) && (position.second < std::size(grid[0])) &&
        (grid[position.first][position.second] != 1 /*wall*/) &&
        (distances[position.first][position.second] == -1 /*not visited*/)
    );
}

int shortestPathInMaze(
    std::vector<std::vector<int>> const &grid,
    std::pair<int, int> const &start,
    std::pair<int, int> const &goal
) {
    int n = static_cast<int>(std::size(grid));
    int m = static_cast<int>(std::size(grid[0]));

    std::vector<std::vector<int>> distances(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int>> q;

    q.push(start);
    distances[start.first][start.second] = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        if (current == goal) {
            return distances[current.first][current.second];
        }

        for (auto const &direction : kDirections) {
            auto next = current + direction;

            if (!isSafe(next, grid, distances)) {
                continue;
            }

            distances[next.first][next.second] = distances[current.first][current.second] + 1;

            q.push({ next.first, next.second });
        }
    }

    return -1; // unreachable
}

int main() {
    std::vector<std::vector<int>> grid {
        /*        0  1  2  3 */
        /* 0 */ { 0, 0, 1, 0 },
        /* 1 */ { 0, 0, 0, 0 },
        /* 2 */ { 1, 0, 1, 0 },
        /* 3 */ { 0, 0, 0, 0 },
    };
    std::pair<int, int> start{ 0, 0 };
    std::pair<int, int> goal{ 3, 3 };

    int steps = shortestPathInMaze(grid, start, goal);
    std::cout << "Shortest path = " << steps << "\n";
    // Expected output: 6
}
