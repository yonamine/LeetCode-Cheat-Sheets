#include <array>
#include <iostream>

constexpr int kMaxAlphabet{26};

struct TrieNode {
    TrieNode() {
        children.fill(nullptr);
    }
    std::array<TrieNode *, kMaxAlphabet> children{};
    bool is_end{false};
    int pass_count{0}; // How many words pass through this node (including end points)
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
            node->pass_count++;
        }
        node->is_end = true;
    }

    int CountWordsWithPrefix(std::string const &prefix) const {
        TrieNode *node = m_root;
        for (auto c : prefix) {
            int index = c - 'a';
            if ((index < 0) || (index >= kMaxAlphabet)) {
                return 0;
            }
            if (node->children[index] == nullptr) {
                return 0;
            }
            node = node->children[index];
        }
        return node->pass_count;
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

    std::cout << "Words with prefix \"te\": " << trie.CountWordsWithPrefix("te") << '\n'; // tea, ted, ten -> 3
    // Words with prefix "te": 3
    std::cout << "Words with prefix \"t\": "  << trie.CountWordsWithPrefix("t") << '\n';  // to, tea, ted, ten -> 4
    // Words with prefix "t": 4
    std::cout << "Words with prefix \"in\": " << trie.CountWordsWithPrefix("in") << '\n'; // in, inn -> 2
    // Words with prefix "in": 2
}
