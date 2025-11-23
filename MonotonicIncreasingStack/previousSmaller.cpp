#include <iostream>
#include <stack>
#include <vector>

// For each position, find index of previous smaller element; -1 if none
const std::vector<int> previousSmaller(std::vector<int> const &numbers) {
    int n = std::size(numbers);
    std::vector<int> result(n, -1);
    std::stack<int> s; // will store indices, with nums[...] is increasing order

    for (int i = 0; i < n; i++) {
        // maintain monotonic increasing stack by value
        while ((s.empty() == false) && (numbers[s.top()] >= numbers[i])) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top(); // index of previous smaller
        }

        s.push(i);
    }

    return result;
}

int main() {
    std::vector<int> numbers { 2, 1, 4, 3 };
    auto previous = previousSmaller(numbers);

    std::cout << "Previous smaller indices: ";
    for (int i : previous) std::cout << i << ' ';
    std::cout << '\n';
    // Previous smaller indices: -1 -1 1 1
}