#include <iostream>
#include <vector>
#include <algorithm>

// Return max number of non-overlapping intervals
int maxNonOverlappingIntervals(std::vector<std::pair<int,int>> intervals) {
    if (intervals.empty()) {
        return 0;
    }

    std::sort(std::begin(intervals),
              std::end(intervals),
              [](auto const &a, auto const &b) {
                  if (a.second != b.second) {
                    return a.second < b.second;
                  }
                  return a.first < b.first;
              });

    int count = 0;
    int last_end = std::numeric_limits<int>::min();

    for (auto const &[ start, end ] : intervals) {
        if (start >= last_end) {
            ++count;
            last_end = end;
        }
    }

    return count;
}

int main() {
    // intervals: (start, end)
    std::vector<std::pair<int,int>> intervals {
        { 1, 2 },
        { 2, 3 },
        { 3, 4 },
        { 1, 3 },
    };

    int answer = maxNonOverlappingIntervals(intervals);
    std::cout << "Max non-overlapping intervals = " << answer << "\n";
    // Expected output: 3 (ex: [1,2], [2,3], [3,4])
}
