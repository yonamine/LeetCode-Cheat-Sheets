#include <iostream>
#include <limits>
#include <vector>

constexpr int kInfinite = std::numeric_limits<int>::max();

int minSubarrayLen(int target, std::vector<int> const &numbers) {
    int left = 0;
    int sum = 0;
    int best = kInfinite;

    for (int right = 0; right < std::size(numbers); right++) {
        sum += numbers[right];

        while (sum >= target) {
            int length = (right - left) + 1;
            best = (length < best) ? length : best;
            sum -= numbers[left];
            left++;
        }
    }

    int result = (best == kInfinite) ? 0 : best;
    return result;
}

int main() {
    std::vector<int> nums { 2, 3, 1, 2, 4, 3 };
    int target = 7;
    int result = minSubarrayLen(target, nums);
    std::cout << "Min length with sum >= " << target << " : " << result << '\n';
}
