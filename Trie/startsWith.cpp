#include <array>
#include <iostream>
#include <memory>

constexpr int kMaxAlphabet{26};

struct TrieNode {
    TrieNode() : is_end{false} {
        children.fill(nullptr);
    }
    std::array<TrieNode *, kMaxAlphabet> children;
    bool is_end{false};
};

class Trie {
public:
    Trie() : m_root{std::make_unique<TrieNode>()} {}

    // Insert a word into the trie
    void Insert(std::string const &word) {
        TrieNode *node = m_root.get();
        for (auto c : word) {
            int index = c - 'a'; // Assume lower case 'a-z'
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->is_end = true;
    }

    // Return true if the word is in the trie
    bool Search(std::string const &word) const {
        const TrieNode *node = FindNode(word);
        return ((node != nullptr) && (node->is_end));
    }

    // Return true if there is any word in the trie that starts with the given prefix
    bool StartsWith(std::string const &prefix) const {
        const TrieNode *node = FindNode(prefix);
        return (node != nullptr);
    }

private:
    const TrieNode *FindNode(std::string const &str) const {
        const TrieNode *node = m_root.get();
        for (auto c : str) {
            int index = c - 'a';

            if ((index < 0) || (index >= kMaxAlphabet)) {
                return nullptr; // out of range
            }

            if (node->children[index] == nullptr) {
                return nullptr;
            }

            node = node->children[index];
        }
        return node;
    }

private:
    std::unique_ptr<TrieNode> m_root;
};

int main() {
    Trie trie;
    trie.Insert("to");
    trie.Insert("tea");
    trie.Insert("ted");
    trie.Insert("ten");
    trie.Insert("in");
    trie.Insert("inn");

    std::cout << std::boolalpha;
    std::cout << "search(\"tea\"): " << trie.Search("tea") << '\n';       // true
    // search("tea"): true
    std::cout << "search(\"te\"): "  << trie.Search("te")  << '\n';       // false
    // search("te"): false
    std::cout << "startsWith(\"te\"): " << trie.StartsWith("te") << '\n'; // true
    // startsWith("te"): true
    std::cout << "startsWith(\"ta\"): " << trie.StartsWith("ta") << '\n'; // false
    // startsWith("ta"): false
}
