#include <algorithm>
#include <iostream>
#include <vector>

using Interval = std::pair<int /* start */, int /* end */>;

std::vector<Interval> intervalIntersection(std::vector<Interval> const &lhs, std::vector<Interval> const &rhs) {
    std::vector<Interval> result;
    int i = 0;
    int j = 0;

    while ((i < std::size(lhs)) && (j < std::size(rhs))) {
        int start = std::max(lhs[i].first, rhs[j].first);
        int end   = std::min(lhs[i].second, rhs[j].second);

        if (start <= end) {
            result.emplace_back(start, end);
        }

        if (lhs[i].second < rhs[j].second) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    std::vector<Interval> lhs {
        {  0,  2 },
        {  5, 10 },
        { 13, 23 },
        { 24, 25 },
    };
    std::vector<Interval> rhs {
        {  1,  5 },
        {  8, 12 },
        { 15, 24 },
        { 25, 26 },
    };

    auto result = intervalIntersection(lhs, rhs);

    std::cout << "Intersections:\n";
    for (auto const &it : result) {
        std::cout << "[" << it.first << ", " << it.second << "]\n";
    }
    std::cout << '\n';
    // Intersections:
    // [1, 2]
    // [5, 5]
    // [8, 10]
    // [15, 23]
    // [24, 24]
    // [25, 25]
}
