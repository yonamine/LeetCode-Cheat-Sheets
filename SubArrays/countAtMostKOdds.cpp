#include <iostream>
#include <vector>

// @note: sliding window + atMost(K) - atMost(K-1)

// count subarrays with at most K odd numbers
long long countAtMostKOdds(std::vector<int> const &numbers, int K) {
    int n = std::size(numbers);
    int left = 0;
    int odd_count = 0;
    long long result = 0;

    auto isOdd = [](int n) -> bool {
        return (n % 2) != 0;
    };

    for (int right = 0; right < n; right++) {
        // Odd number
        if (isOdd(numbers[right])) {
            odd_count++;
        }

        while (odd_count > K) {
            if (isOdd(numbers[left])) {
                odd_count--;
            }
            left++;
        }

        // All subarrays ending at right, starting from [left..right]
        result += (right - left) + 1;
    }
    return result;
}

long long countSubArraysExactlyKOdds(std::vector<int> const &numbers, int K) {
    if (K < 0) {
        return 0;
    }
    return countAtMostKOdds(numbers, K) - countAtMostKOdds(numbers, K - 1);
}

int main() {
    std::vector<int> numbers { 1, 2, 3, 4 };
    int K = 2;
    long long result = countSubArraysExactlyKOdds(numbers, K);
    std::cout << "Number of subarrays with exactly " << K << " odd numbers: " << result << '\n';
    // Number of subarrays with exactly 2 odd numbers: 2
}
