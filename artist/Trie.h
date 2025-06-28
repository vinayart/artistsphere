#pragma once

#include <QString>
#include <vector>
#include <unordered_map>

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
    std::vector<QString> searchPrefix(const QString& prefix) const;

    void clear();  // NEW for reuse

private:
    TrieNode* root;

    void collectAllWords(TrieNode* node, const QString& prefix, std::vector<QString>& result) const;
    void deleteTrie(TrieNode* node);
};
