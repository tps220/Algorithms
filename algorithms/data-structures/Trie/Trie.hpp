#include <iostream>
#include <string>
#include <unordered_map>

struct TrieNode {
  std::unordered_map<char, TrieNode*> map;
  TrieNode() : map(std::unordered_map<char, TrieNode*>()) {}
};


class Trie {
public:
  Trie();
  ~Trie();
  void insert(std::string word);
  bool searchWord(std::string word);
  bool searchPrefix(std::string prefix);
private:
  TrieNode* root;
  //Helper Methods
  void destroy(TrieNode* root);
  TrieNode* find(std::string str, TrieNode* root);
  //Recursive Implementations
  void insert(std::string &word, TrieNode* root, size_t idx);
  bool searchWord(std::string &word, TrieNode* root, size_t idx);
  bool searchPrefix(std::string &prefix, TrieNode* root, size_t idx);
};
