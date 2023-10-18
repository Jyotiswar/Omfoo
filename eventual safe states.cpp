#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<bool>& vis, vector<bool>& safe) {
        if (safe[i])
            return true;
        if (vis[i])
            return false;
        vis[i] = true;

        bool isSafe = true;
        for (auto edge : adj[i]) {
            isSafe &= dfs(edge, adj, vis, safe);
        }

        return safe[i] = isSafe;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> safe(V, false), vis(V, false);
        for (int i = 0; i < V; ++i) {
            if (!vis[i])
                dfs(i, adj, vis, safe);
        }

        vector<int> out;
        for (int i = 0; i < V; ++i)
            if (safe[i])
                out.push_back(i);

        return out;
    }
};

int main() {
    Solution solution;

    int V = 6;
    vector<int> adj[V];

    // Define the adjacency list for a directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);

    vector<int> eventualSafe = solution.eventualSafeNodes(V, adj);

    cout << "Eventual Safe Nodes: ";
    for (int node : eventualSafe) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
