#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector< vector<char> > &grid) {
        int count = 0;
        vector< vector<char> > map = grid;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                if (map[i][j] == '1') {
                    dfs(map, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector< vector<char> > &map, int i, int j) {
        if (i < 0 || i >= map.size() || j < 0 || j >= map[i].size() || map[i][j] != '1') {
            return;
        }    
        map[i][j] = '0';
        //search north, south, east, west
        dfs(map, i + 1, j);
        dfs(map, i - 1, j);
        dfs(map, i, j + 1);
        dfs(map, i, j - 1);
    }
};
