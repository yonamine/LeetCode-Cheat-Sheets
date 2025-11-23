#include <iostream>
#include <vector>

std::vector<int> intersectionWithDuplicates(std::vector<int> const &lhs, std::vector<int> const &rhs) {
    std::vector<int> result;
    int i = 0;
    int j = 0;

    while ((i < std::size(lhs)) && (j < std::size(rhs))) {
        if (lhs[i] == rhs[j]) {
            result.push_back(lhs[i]);
            i++;
            j++;
        } else if (lhs[i] < rhs[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    std::vector<int> lhs{ 1, 2, 2, 3, 5 };
    std::vector<int> rhs{ 2, 2, 4, 5, 6 };

    auto intersection = intersectionWithDuplicates(lhs, rhs);

    // Intersection: 2 2 5
    std::cout << "Intersection: ";
    for (int x : intersection) std::cout << x << ' ';
    std::cout << '\n';
}
