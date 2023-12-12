#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    bool isValid(int& i, int& j, int& n, int& m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int traverse(int i, int j, vector<vector<int>>& M, int& n, int& m) {
        int out = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        for (int d = -1; d <= 1; ++d) {
            int x = i + d;
            int y = j + 1;
            if (isValid(x, y, n, m))
                out = max(out, traverse(x, y, M, n, m));
        }
        return dp[i][j] = out + M[i][j];
    }

    int maxGold(int n, int m, vector<vector<int>> M) {
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int out = 0;
        for (int i = 0; i < n; ++i) {
            out = max(out, traverse(i, 0, M, n, m));
        }
        return out;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the maxGold function with an example matrix
    int n = 3, m = 4;
    vector<vector<int>> M = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3}
    };

    int result = solution.maxGold(n, m, M);

    // Display the result
    cout << "Maximum amount of gold that can be collected: " << result << endl;

    return 0;
}
