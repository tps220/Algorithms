#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int idx) {
        if (idx == word.length()) {
            return true;
        }
        else if (i < 0 || j < 0 || i == board.size() || j == board[i].size()) {
            return false;
        }
        else if (board[i][j] != word[idx]) {
            return false;
        }
        board[i][j] -= 60;
        bool retval = dfs(board, i + 1, j, word, idx + 1) || 
                      dfs(board, i - 1, j, word, idx + 1) || 
                      dfs(board, i, j + 1, word, idx + 1) || 
                      dfs(board, i, j - 1, word, idx + 1);
        board[i][j] += 60;
        return retval;
    }
};
