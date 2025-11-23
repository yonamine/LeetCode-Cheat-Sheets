#include <iostream>
#include <optional>
#include <queue>
#include <vector>

// Return k largest elements using a min-heap of size k
const std::vector<int> topKLargest(std::vector<int> const &numbers, int k) {
    if (k <= 0) {
        return {};
    }

    k = (k > std::size(numbers)) ? std::size(numbers) : k;

    // min-heap to keep k largest elements
    std::priority_queue<
        int,
        std::vector<int>,
        std::greater<>
    > min_heap;

    for (int number : numbers) {
        if (std::size(min_heap) < k) {        // fill the heap first
            min_heap.push(number);
        } else if (number > min_heap.top()) { // if current element is larger than the smallest in heap, it belongs to the top k
            min_heap.pop();
            min_heap.push(number);
        }
    }

    std::vector<int> result;
    result.reserve(std::size(min_heap));
    while (!min_heap.empty()) {
        result.push_back(min_heap.top());
        min_heap.pop();
    }

    return result; // can be in any order
}

int main() {
    std::vector<int> numbers { 5, 1, 9, 3, 7, 2, 8 };
    int k = 3;
    auto top = topKLargest(numbers, k);
    std::cout << "Top " << k << " largest elements: ";
    for (int x : top) std::cout << x << ' ';
    std::cout << '\n';
    // Top 3 largest elements: 7 8 9
}
