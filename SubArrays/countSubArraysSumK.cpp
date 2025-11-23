#include <iostream>
#include <vector>
#include <unordered_map>

// Count the number of subarrays whose sum equals k
int countSubArraysSumK(std::vector<int> const &numbers, int k) {
    std::unordered_map<int, int> frequencies; // prefixSum -> how many times seen
    frequencies[0] = 1; // empty prefix has sum 0

    int current_sum = 0;
    int count = 0;

    for (auto const &n : numbers) {
        current_sum += n;
        int need = current_sum - k;
        if (frequencies.find(need) != frequencies.end()) {
            count += frequencies[need];
        }
        frequencies[current_sum]++;
    }

    return count;
}

int main() {
    std::vector<int> numbers { 1, 1, 1 };
    int k = 2;
    int result = countSubArraysSumK(numbers, k);
    std::cout << "Number of subarrays with sum = " << k << " : " << result << '\n';
    // Number of subarrays with sum = 2 : 2
}
