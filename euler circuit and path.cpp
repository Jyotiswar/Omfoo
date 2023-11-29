#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int isEulerCircuit(int v, vector<int> adj[]) {
        int even = 0, odd = 0;
        for (int i = 0; i < v; i++) {
            if (adj[i].size() & 1)
                ++odd;
            else
                ++even;
        }

        return even == v ? 2 : (odd > 0 && odd == 2);
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create an undirected graph represented by an adjacency list
    int V = 4;
    vector<int> adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2, 3};
    adj[2] = {1};
    adj[3] = {0, 1};

    // Check if the graph has an Euler circuit
    int result = solution.isEulerCircuit(V, adj);

    if (result == 2) {
        cout << "The graph has an Euler circuit.\n";
    } else if (result) {
        cout << "The graph has an Euler path.\n";
    } else {
        cout << "The graph does not have an Euler circuit or path.\n";
    }

    return 0;
}
