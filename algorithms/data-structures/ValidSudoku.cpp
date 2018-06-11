#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_set<string> row, col, grid;        
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board.size(); j++) {
                char number = board[i][j];
                if (number != '.' && number != ',') {
                    string grid_insertion(1, '0' + i / 3);
                    grid_insertion.append(1, number);
                    grid_insertion.append(1, '0' + j / 3);
                    string row_insertion(1, '0' + i);
                    row_insertion.append(1, number);
                    string col_insertion(1, '0' + j);
                    col_insertion.append(1, number);
                    if (!grid.insert(grid_insertion).second ||
                        !row.insert(row_insertion).second   ||
                        !col.insert(col_insertion).second) {
                        return false;
                    }
                }
                
            }
        }
        return true;
    }

};
