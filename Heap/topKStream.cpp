#include <iostream>
#include <queue>
#include <vector>

// Maintain a min-heap of size k for streaming top-k largest elements
const std::vector<int> getTopK(int k, std::vector<int> const &numbers) {
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;

    for (int number : numbers) {
        if (number <= 0) {
            continue;
        }

        if (k > std::size(min_heap)) {
            min_heap.push(number);
            continue;
        }

        if (number > min_heap.top()) {
            min_heap.pop();
            min_heap.push(number);
            continue;
        }
    }

    std::vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top());
        min_heap.pop();
    }

    return result; // may be unsorted
}

int main() {
    int k = 3;
    std::vector<int> numbers { 5, 1, 9, 3, 7, 2, 8 };
    auto top = getTopK(k, numbers);
    std::cout << "Top 3 elements from stream: ";
    for (int x : top) std::cout << x << ' ';
    std::cout << '\n';
    // Top 3 elements from stream: 7 8 9
}
