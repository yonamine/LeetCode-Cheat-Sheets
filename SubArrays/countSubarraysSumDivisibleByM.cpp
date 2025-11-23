#include <iostream>
#include <vector>
#include <unordered_map>

// Count sub-arrays whose sum is divisible by M
long long countSubArraysSumDivisibleByM(std::vector<int> const &numbers, int M) {
    std::unordered_map<int, long long> frequencies; // remainder -> count
    long long counter = 0;
    long long prefix_sum = 0;

    frequencies[0] = 1; // Empty prefix has remainder 0

    for (auto const &n : numbers) {
        prefix_sum += n;
        // int remainder  = (((prefix_sum % M) + M) % M); // handle negatives
        int remainder_negative = prefix_sum % M;         // C++ remainder , may be negative
        int remainder_shifted  = remainder_negative + M; // shift up by M
        int remainder          = remainder_shifted % M;  // normalize to [0, M - 1]

        if (frequencies.find(remainder) != frequencies.end()) {
            counter += frequencies[remainder]; // all previous prefixes with same remainder
        }

        frequencies[remainder ]++;
    }

    return counter;
}

int main() {
    std::vector<int> numbers { 4, 5, 0, -2, -3, 1 };
    int M = 5;
    long long result = countSubArraysSumDivisibleByM(numbers, M);
    std::cout << "Number of subarrays with sum divisible by " << M << " : " << result << '\n';
    // Number of subarrays with sum divisible by 5 : 7
}
