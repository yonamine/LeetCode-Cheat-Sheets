#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(std::string const &str) {
    int left = 0;
    int right = std::size(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::vector<std::string> inputs{ "abba", "abca", "abcba" };
    for (auto const &input : inputs) {
        std::cout << "Is '" << input << "' a palindrome? "
                  << isPalindrome(input) << '\n';
    }
}
