#include <array>
#include <iostream>
#include <string>
#include <vector>

constexpr int kMaxAlphabet{26};

struct TrieNode {
    TrieNode() : is_end{false} {
        children.fill(nullptr);
    }
    std::array<TrieNode *, kMaxAlphabet> children{};
    bool is_end{false};
};

class Trie {
public:
    Trie() : m_root{new TrieNode()} {}

    void Insert(std::string const &word) {
        TrieNode *node = m_root;
        for (auto c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->is_end = true;
    }

    std::vector<std::string> Autocomplete(std::string const &prefix) const {
        TrieNode *node = m_root;

        // 1) Walk to the prefix node
        for (auto c : prefix) {
            int index = c - 'a';
            if ((index < 0) || (index >= kMaxAlphabet) || (node->children[index] == nullptr)) {
                return {}; // empty, prefix not found
            }
            node = node->children[index];
        }

        // 2) DFS from this node, building words
        std::vector<std::string> result;
        std::string current = prefix;
        dfs(node, current, result);
        return result;
    }

private:
    void dfs(const TrieNode *node, std::string &current, std::vector<std::string> &result_out) const {
        if (node->is_end) {
            result_out.push_back(current);
        }

        for (int i = 0; i < kMaxAlphabet; i++) {
            if (node->children[i] == nullptr) {
                continue;
            }

            current.push_back('a' + i);
            dfs(node->children[i], current, result_out);
            current.pop_back(); // backtrack
        }
    }
private:
    TrieNode *m_root{nullptr};
};

int main() {
    Trie trie;
    trie.Insert("to");
    trie.Insert("tea");
    trie.Insert("ted");
    trie.Insert("ten");
    trie.Insert("in");
    trie.Insert("inn");

    auto words = trie.Autocomplete("te");

    std::cout << "Autocomplete for \"te\": ";
    for (const auto& w : words) std::cout << w << ' ';
    std::cout << '\n';
    // Autocomplete for "te": tea ted ten
}
