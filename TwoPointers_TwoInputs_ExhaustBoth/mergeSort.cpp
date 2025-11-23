#include <iostream>
#include <vector>

std::vector<int> mergeSorted(std::vector<int> const &lhs, std::vector<int> const &rhs) {
    std::vector<int> result;

    int i = 0;
    int j = 0;

    // 1. Enquanto nenhum dos dois arrays terminaram, adicione no std::vector
    while ((i < std::size(lhs)) && (j < std::size(rhs))) {
        if (lhs[i] <= rhs[j]) {
            result.push_back(lhs[i]);
            i++;
        } else {
            result.push_back(rhs[j]);
            j++;
        }
    }

    // "Exhaust both"

    // 2. Copia o resto dos valores do lhs
    while (i < std::size(lhs)) {
        result.push_back(lhs[i]);
        i++;
    }

    // 3. Copia o resto dos valores do rhs
    while (j < std::size(rhs)) {
        result.push_back(rhs[j]);
        j++;
    }

    return result;
}

int main() {
    std::vector<int> a{ 1, 3, 5, 7 };
    std::vector<int> b{ 2, 4, 6 };

    auto merged = mergeSorted(a, b);

    std::cout << "Merged: ";
    for (int x : merged) std::cout << x << ' ';
    std::cout << '\n';
}
