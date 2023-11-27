#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

class Solution {
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        vector<int> dsu(V, -1);

        vector<set<int>> g(V);

        for (int i = 0; i < V; i++) {
            for (auto x : adj[i])
                g[i].insert(x);
        }

        function<int(int)> find = [&](int p) -> int {
            if (dsu[p] < 0)
                return p;
            return dsu[p] = find(dsu[p]);
        };

        auto merge = [&](int x, int y) {
            if (dsu[x] > dsu[y])
                swap(x, y);

            dsu[x] += dsu[y];
            dsu[y] = x;
        };

        vector<bool> vis(V, 0);

        function<bool(int, int)> dfs = [&](int node, int par) -> bool {
            bool ans = 0;
            vis[node] = 1;

            for (auto child : g[node]) {
                if (child != par) {
                    int x = find(node);
                    int y = find(child);

                    if (x == y)
                        return 1;

                    merge(x, y);

                    ans = ans or dfs(child, node);
                }
            }

            return ans;
        };

        bool ans = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                ans = ans or dfs(i, -1);
            }
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create an undirected graph represented by an adjacency list
    int V = 4;
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {2};

    // Check if the graph has a cycle
    bool hasCycle = solution.detectCycle(V, adj);

    if (hasCycle) {
        cout << "The graph has a cycle.\n";
    } else {
        cout << "The graph does not have a cycle.\n";
    }

    return 0;
}
