#include "Trie.hpp"


//-----------Constructors----------------//
Trie::Trie() {
    this -> root = new TrieNode();
}

Trie::~Trie() {
    destroy(root);
}

void Trie::destroy(TrieNode* root) {
    if (root == NULL) {
        return;
    }
    for (auto it = root -> map.begin(); it != root -> map.end(); it++) {
        destroy(it -> second);
    }
    delete root;
}

//---------------Insertion--------------//
void Trie::insert(std::string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.length(); i++) {
        if (node -> map.find(word[i]) != node -> map.end()) {
            node = node -> map[word[i]];
        }
        else {
            TrieNode* insertion = new TrieNode();
            node -> map.insert(std::pair<char, TrieNode*>(word[i], insertion));
            if (i != word.length() - 1) {
                node = insertion;
            }
        }
    }
    node -> map.insert(std::pair<char, TrieNode*>('*', NULL));
}

//-----------Find Method----------//
TrieNode* Trie::find(std::string str, TrieNode* root) {
    TrieNode* node = root;
    for (int i = 0; i < str.length(); i++) {
        if (node -> map.find(str[i]) == node -> map.end()) {
            return NULL;
        }
        if (i != str.length() - 1) {
            node = node -> map[str[i]];
        }
    }
    return node;
}


//---------------Search For Word--------------//
bool Trie::searchWord(std::string word) {
    TrieNode* node = find(word, root);
    return node != NULL && node -> map.find('*') != node -> map.end();
}


//----------------Search For Prefix------------------//
bool Trie::searchPrefix(std::string prefix) {
    TrieNode* node = find(prefix, root);
    return node != NULL && node -> map.find('*') == node -> map.end();
}
