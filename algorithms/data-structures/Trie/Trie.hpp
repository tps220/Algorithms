#include <iostream>
#include <string>
#include <unordered_map>

struct TrieNode {
  std::unordered_map<char, TrieNode*> map;
  bool isEnd;
  TrieNode() : map(std::unordered_map<char, TrieNode*>()), isEnd(false) {}
  TrieNode(bool end) : map(std::unordered_map<char, TrieNode*>()), isEnd(end) {}
};


class Trie {
public:
  Trie();
  ~Trie();
  void insert(std::string word);
  bool search(std::string word);
  bool startsWith(std::string prefix);
private:
  TrieNode* root;
  void insert(std::string word, TrieNode* root);
  bool search(std::string word, TrieNode* root);
  bool startsWith(std::string prefix, TrieNode* root);
};
