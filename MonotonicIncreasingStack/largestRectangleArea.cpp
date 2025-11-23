#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

// Largest rectangle in histogram using a monotonic increasing stack
int largestRectangleArea(std::vector<int> const &heights) {
    int n = std::size(heights);
    std::stack<int> s; // will store indices, with heights increasing
    int maxArea = 0;

    for (int i = 0; i <= n; ++i) {
        int current_height = (i == n) ? 0 : heights[i]; // sentinel 0 at the end

        // maintain increasing stack
        while ((s.empty() == false) && (current_height < heights[s.top()])) {
            int height = heights[s.top()];
            s.pop();

            int left_boundary = -1;

            if (s.empty()) {
                left_boundary = 0;
            } else {
                left_boundary = s.top() + 1;
            }

            int right_boundary = i - 1;
            int width = right_boundary - left_boundary + 1;

            int area = height * width;

            maxArea = std::max(maxArea, area);
        }

        s.push(i);
    }

    return maxArea;
}

int main() {
    std::vector<int> heights { 2, 1, 5, 6, 2, 3 };
    int result = largestRectangleArea(heights);
    std::cout << "Largest rectangle area: " << result << '\n';
    // Largest rectangle area: 10
}
