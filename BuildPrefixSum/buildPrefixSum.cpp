#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, std::vector<int> const &numbers) {
    os << "{ ";
    char delimiter[3] { '\0', ' ', '\0' };
    for (auto n : numbers) {
        os << delimiter << n;
        delimiter[0] = ',';
    }
    os << " }";
    return os;
}

// Build prefix sum array: prefix[i + 1] = sum of nums[0..i]
const std::vector<int> buildPrefixSum(std::vector<int> const &numbers) {
    std::vector<int> prefix(std::size(numbers) + 1, 0);
    for (int i = 0; i < std::size(numbers); i++) {
        prefix[i + 1] = prefix[i] + numbers[i];
    }
    return prefix;
}

// Query sum on range [L, R] using prefix sum
int rangeSum(std::vector<int> const &prefix, int left, int right) {
    // Assume 0 <= L <= R < n
    int L = prefix[left];
    int R = prefix[right + 1];
    int result = R - L;
    std::cout << R << " - " << L << " = " << result << '\n';
    return result;
}

int main() {
    std::vector<int> numbers { 1, 2, 3, 4, 5 };
    auto prefix = buildPrefixSum(numbers);
    std::cout << "Prefix Sum result: " << prefix << '\n';

    std::cout << "Sum [0, 2] = " << rangeSum(prefix, 0, 2) << '\n'; // 1 + 2 + 3
    // Output: Sum [0, 2] = 6
    std::cout << "Sum [1, 3] = " << rangeSum(prefix, 1, 3) << '\n'; // 2 + 3 + 4
    // Output: Sum [1, 3] = 9
    std::cout << "Sum [2, 4] = " << rangeSum(prefix, 2, 4) << '\n'; // 3 + 4 + 5
    // Output: Sum [2, 4] = 12
}
