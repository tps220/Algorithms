#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> result;
        vector<pair<int, int>> edges;
        for (int i = 0; i < buildings.size(); i++) {
            int left = buildings[i][0];
            int right = buildings[i][1];
            int height = buildings[i][2];
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        
        sort(edges.begin(), edges.end());
        multiset<int> heap;
        heap.insert(0);
        int prevMax = 0;
        for (int i = 0; i < edges.size(); i++) {
            pair<int, int> e = edges[i];
            if (e.second < 0) {
                heap.insert(-e.second);
            } else {
                heap.erase(heap.find(e.second));
            }
            int curMax = *(heap.rbegin());
            if (curMax != prevMax) {
                result.push_back(make_pair(e.first, curMax));
                prevMax = curMax;
            }
        }
        return result;
    }
};
