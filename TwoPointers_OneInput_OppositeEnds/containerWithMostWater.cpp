/*

Given an array arr[] of non-negative integers, where each element arr[i]
represents the height of the vertical lines, find the maximum amount of
water that can be contained between any two lines, together with the x-axis.

Examples:
Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: 5 and 3 are 2 distance apart. So the size of the base = 2.
Height of container = min(5, 3) = 3. So total area = 3 * 2 = 6.

Input: arr[] = [3, 1, 2, 4, 5]
Output: 12
Explanation: 5 and 3 are 4 distance apart. So the size of the base = 4.
Height of container = min(5, 3) = 3. So total area = 4 * 3 = 12.

Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
Output: 25
Explanation: 8 and 5 are 5 distance apart. So the size of the base = 5.
Height of container = min(8, 5) = 5. So, total area = 5 * 5 = 25.


 */
#include <iostream>
#include <vector>

int maxArea_naive(std::vector<int> const &heights) {
    int size = std::size(heights);
    int best = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int height = std::min(heights[i], heights[j]);
            int width = j - i;
            int area = height * width;
            best = std::max(best, area);
        }
    }
    return best;
}

int maxArea(std::vector<int> const &heights) {
    int left = 0;
    int right = std::size(heights) - 1;
    int best = 0;

    while (left < right) {
        int height = std::min(heights[left], heights[right]);
        int width = right - left;
        int area = height * width;

        best = std::max(best, area);

        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    return best;
}

int main() {
    {
        std::vector<int> heights { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        // Output: 49
        // int result = maxArea(heights);
        int result = maxArea_naive(heights);
        std::cout << "Max Area: " << result << '\n';
    }
    {
        std::vector<int> heights { 2, 1, 8, 6, 4, 6, 5, 5 };
        // Output: 25
        int result = maxArea(heights);
        std::cout << "Max Area: " << result << '\n';
    }
}
