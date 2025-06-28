#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const QString& word) {
    TrieNode* node = root;
    for (QChar ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

bool Trie::search(const QString& word) const {
    TrieNode* node = root;
    for (QChar ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            return false;
        }
        node = node->children[ch];
    }
    return node->isEndOfWord;
}

std::vector<QString> Trie::searchPrefix(const QString& prefix) const {
    std::vector<QString> result;
    TrieNode* node = root;

    for (QChar ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return result;
        }
        node = node->children[ch];
    }

    collectAllWords(node, prefix, result);
    return result;
}

void Trie::collectAllWords(TrieNode* node, const QString& prefix, std::vector<QString>& result) const {
    if (node->isEndOfWord) {
        result.push_back(prefix);
    }

    for (const auto& pair : node->children) {
        collectAllWords(pair.second, prefix + pair.first, result);
    }
}

void Trie::deleteTrie(TrieNode* node) {
    if (!node) return;
    for (auto& pair : node->children) {
        deleteTrie(pair.second);
    }
    delete node;
}

void Trie::clear() {
    deleteTrie(root);
    root = new TrieNode();
}
