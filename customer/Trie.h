#pragma once
#include <unordered_map>
#include <QString>
#include <vector>

// ✅ Custom hash specialization for QChar
namespace std {
    template<>
    struct hash<QChar> {
        std::size_t operator()(const QChar& ch) const noexcept {
            return std::hash<ushort>()(ch.unicode());
        }
    };
}

class TrieNode {
public:
    std::unordered_map<QChar, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    Trie();
    void insert(const QString& word);
    bool search(const QString& word) const;

    // ✅ Add this for autocomplete
    std::vector<QString> searchPrefix(const QString& prefix) const;

private:
    TrieNode* root;

    void collectAllWords(TrieNode* node, const QString& prefix, std::vector<QString>& result) const;
};
