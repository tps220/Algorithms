#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
        vector< unordered_set<int> > graph = make_graph(prerequisites, numCourses);
        vector<bool> visited(numCourses, false), currentPath(numCourses, false);
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && dfs_cycle(graph, visited, currentPath, i)) {
                return false;
            }
        }
        return true;
    }
private:
    vector< unordered_set<int> > make_graph(vector< pair<int, int> >& prerequisites, const int numCourses) {
        vector< unordered_set<int> > graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first].insert(prerequisites[i].second);
        }
        return graph;
    }
    bool dfs_cycle(vector< unordered_set<int> > &graph, vector<bool> &visited, vector<bool>& currentPath, int node) {
        if (visited[node]) {
            return false;
        }
        //mark as visited
        currentPath[node] = true;
        visited[node] = true;
        for (int element: graph[node]) {
            if (currentPath[element] || dfs_cycle(graph, visited, currentPath, element)) {
                return true;
            }
        }
        //unmark to unvisited
        currentPath[node] = false;
        return false;
    }
};
