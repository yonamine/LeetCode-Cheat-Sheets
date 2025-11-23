#include <iostream>
#include <unordered_map>
#include <vector>

// Count the number of subarrays whose sum equals k
int countSubarraysWithSumK(std::vector<int> const &numbers, int k) {
    std::unordered_map<int, int> frequencies; // prefix sum -> how many times seen
    frequencies[0] = 1;
    int current_sum = 0;
    int count = 0;
    for (auto const &current : numbers) {
        current_sum += current;
        int need = current_sum - k;
        if (frequencies.find(need) != frequencies.end()){
            count += frequencies[need];
        }
        frequencies[current_sum]++;
    }
    return count;
}

int main() {
    std::vector<int> nums { 1, 1, 1 };
    int k = 2;
    int result = countSubarraysWithSumK(nums, k);
    std::cout << "Number of subarrays with sum = " << k << " : " << result << '\n';
    // Number of subarrays with sum = 2 : 2
}