#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
        vector<vector<int>> transitive(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                transitive[i][j] = graph[i][j];
                if (i == j) {
                    transitive[i][j] = 1;
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (transitive[i][k] && transitive[k][j]) {
                        transitive[i][j] = 1;
                    }
                }
            }
        }

        return transitive;
    }
};

int main() {
    Solution solution;

    int N = 4;
    vector<vector<int>> graph = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1}
    };

    vector<vector<int>> transitiveClosureMatrix = solution.transitiveClosure(N, graph);

    cout << "Transitive Closure Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << transitiveClosureMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
