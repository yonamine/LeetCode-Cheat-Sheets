#include <iostream>
#include <vector>
#include <stack>

// For each position, find index of next smaller element to the right; -1 if none.
const std::vector<int> nextSmallerToRight(std::vector<int> const &numbers) {
    int n = std::size(numbers);
    std::vector<int> result(n, -1);
    std::stack<int> s; // will store indices, nums[...] increasing

    for (int i = n - 1; i >= 0; --i) {
        //
        while ((s.empty() == false) && numbers[s.top()] >= numbers[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top(); //
        }

        s.push(i);
    }

    return result;
}

int main() {
    std::vector<int> numbers { 2, 1, 4, 3 };
    auto next = nextSmallerToRight(numbers);

    std::cout << "Next smaller indices: ";
    for (int i : next) std::cout << i << ' ';
    std::cout << '\n';
    // Next smaller indices: 1 -1 3 -1
}
