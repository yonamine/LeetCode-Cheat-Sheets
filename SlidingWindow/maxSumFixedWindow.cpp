#include <algorithm>
#include <iostream>
#include <vector>

int maxSumFixedWindow(std::vector<int> const &numbers, int k) {
    int windowSum = 0;

    // Initial Sum: 1st window
    for (int i = 0; i < k; i++) {
        windowSum += numbers[i];
    }

    int best = windowSum;

    // Sliding the Window
    for (int right = k; right < std::size(numbers); right++) {
        windowSum += numbers[right];     // Include new value
        windowSum -= numbers[right - k]; // Exclude old value
        best = std::max(best, windowSum);
    }

    return best;
}

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
    int k = 3;
    int result = maxSumFixedWindow(v, k);
    std::cout << "Max sum (k = 3): " << result << '\n';
    // Max sum (k = 3): 15
}
