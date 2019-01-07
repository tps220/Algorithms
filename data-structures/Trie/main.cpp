#include "Trie.hpp"
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    //Create a dictionairy of words
    vector<string> dictionary;
    ifstream fd("words.txt");
    if (!fd.is_open()) {
        cout << "The file words.txt could not be found" << endl;
        return 1;
    }
    std::string line;
    while (getline(fd, line)) {
        dictionary.push_back(line);
    }
    fd.close();

    //Input those words into a Trie
    Trie *trie = new Trie();
    for (int i = 0; i < dictionary.size(); i++) {
        trie -> insert(dictionary[i]);
    }

    //Test the Trie
    for (int i = 0; i < dictionary.size(); i++) {
        if (!trie -> searchWord(dictionary[i])) {
            cout << "FAILED to find " << dictionary[i] << endl;
        }
        if (trie -> searchPrefix(dictionary[i])) {
            cout << "FAILED The word " << dictionary[i] << " is not a prefix" << endl;
        }
    }
    
    //Destroy the triee
    delete trie;
}
