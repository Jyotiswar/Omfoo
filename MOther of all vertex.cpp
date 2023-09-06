#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int i, vector<int> adj[], vector<int>& vis, vector<int>& topo) {
        vis[i] = 1;
        for (auto edge : adj[i]) {
            if (!vis[edge]) {
                dfs(edge, adj, vis, topo);
            }
        }
        topo.push_back(i);
    }

    int findMotherVertex(int V, vector<int> adj[]) {
        int cnt = 0;
        vector<int> vis(V, 0), topo;
        for (int i = 0; i < V; ++i) {
            if (!vis[i])
                dfs(i, adj, vis, topo);
        }

        if (topo.size() == V) {
            int motherVer = topo.back();
            vis.assign(V, 0);
            topo.clear();
            dfs(motherVer, adj, vis, topo);
            if (topo.size() == V)
                return motherVer;
        }

        return -1;
    }
};

int main() {
    Solution solution;
    int V = 7; // Number of vertices
    vector<int> adj[V];

    // Define the edges of the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[4].push_back(1);
    adj[6].push_back(4);
    adj[5].push_back(6);
    adj[5].push_back(2);
    adj[6].push_back(0);

    int motherVertex = solution.findMotherVertex(V, adj);
    if (motherVertex != -1) {
        cout << "The mother vertex is: " << motherVertex << endl;
    } else {
        cout << "There is no mother vertex in the graph." << endl;
    }

    return 0;
}
