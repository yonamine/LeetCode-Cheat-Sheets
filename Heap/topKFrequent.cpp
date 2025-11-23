#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

// Return k most frequent elements
const std::vector<int> topKFrequent(std::vector<int> const &numbers, int k) {
    if (k <= 0) {
        return {};
    }

    // 1) Count frequencies
    std::unordered_map<int, int> frequencies;
    for (int number : numbers) {
        frequencies[number]++;
    }

    // 2) Min-heap: (frequency, value)
    using Pair = std::pair<int, int>;
    auto cmp = [](const Pair& a, const Pair& b) {
        return a.first > b.first; // min-heap by freq
    };

    std::priority_queue<
        Pair,
        std::vector<Pair>,
        decltype(cmp)
    > min_heap(cmp);

    for (auto const &[ value, f ] : frequencies) {
        if (std::size(min_heap) < k) {
            min_heap.push({ f, value });
        } else if (f > min_heap.top().first) {
            min_heap.pop();
            min_heap.push({ f, value });
        }
    }

    // 3) Extract result
    std::vector<int> result;
    result.reserve(std::size(min_heap));
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }

    return result;
}

int main() {
    std::vector<int> numbers { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    auto answers = topKFrequent(numbers, k);

    std::cout << "Top " << k << " frequent elements: ";
    for (auto answer : answers) std::cout << answer << ' ';
    std::cout << '\n';
    // Top 2 frequent elements: 2 1
}
