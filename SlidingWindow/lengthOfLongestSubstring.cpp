#include <algorithm>
#include <iostream>
#include <string>
#include <map>


int lengthOfLongestSubstring(std::string const &s) {
    std::map<char, int> frequencies;
    int left = 0;
    int best = 0;
    int size = std::size(s);

    for (int right = 0; right < size; right++) {
        char c = s[right];
        frequencies[c]++;

        // c has added more than once, repeat the window
        while (frequencies[c] > 1) {
            char left_char = s[left];
            frequencies[left_char]--;
            left++;
        }

        int length = (right - left) + 1;
        best = std::max(best, length);
    }

    return best;
}

int main() {
    std::string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    std::cout << "Length of longest substring without repeating chars: " << result << '\n';
    // Length of longest substring without repeating chars: 3
}
