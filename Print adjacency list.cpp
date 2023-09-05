#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
        vector<vector<int>> adjList(V);
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }
};

int main() {
    Solution solution;
    int V = 4; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

    vector<vector<int>> adjList = solution.printGraph(V, edges);

    // Printing the adjacency list representation of the graph
    for (int i = 0; i < V; i++) {
        cout << "Adjacency list for vertex " << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
