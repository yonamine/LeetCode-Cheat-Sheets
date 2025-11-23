#include <iostream>
#include <optional>
#include <vector>

std::optional<
    std::pair<int, int>
> twoSumSorted(std::vector<int> const &input, int target) {
    int left = 0;
    int right = std::size(input) - 1;

    while (left < right) {
        int sum = input[left] + input[right];

        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else /* sum == target */ {
            return std::make_pair(left, right);
        }

    }

    return std::nullopt;
}

int main() {
    // input shall be sorted
    std::vector<int> input { 1, 3, 4, 5, 7, 10, 11 };
    {
        int target = 9;
        auto result = twoSumSorted(input, target);
        if (result.has_value()) {
            std::cout << "Indexes: "
                      << result.value().first << ", "
                      << result.value().second << '\n';
        } else {
            std::cout << "No values for target\n";
        }
    }
}
