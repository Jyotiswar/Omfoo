#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int sum = 0;
        for (int i = 0; i < V; ++i) {
            sum += adj[i].size();
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // Example usage:
    int V = 5;  // Number of vertices
    vector<int> adj[V];

    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);

    // Calculate the sum of dependencies
    int result = solution.sumOfDependencies(adj, V);

    // Display the result
    cout << "Sum of dependencies: " << result << endl;

    return 0;
}
