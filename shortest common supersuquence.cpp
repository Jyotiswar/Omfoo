#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LCS(string& X, string& Y, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (X[i] == Y[j])
            return dp[i][j] = 1 + LCS(X, Y, i - 1, j - 1, dp);

        return dp[i][j] = max(LCS(X, Y, i, j - 1, dp), LCS(X, Y, i - 1, j, dp));
    }

    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int lcs = LCS(X, Y, m - 1, n - 1, dp);
        return m + n - lcs;
    }
};

int main() {
    Solution sol;
    string X, Y;
    cout << "Enter the first string (X): ";
    cin >> X;
    cout << "Enter the second string (Y): ";
    cin >> Y;

    int result = sol.shortestCommonSupersequence(X, Y, X.length(), Y.length());

    cout << "The length of the shortest common supersequence is: " << result << endl;

    return 0;
}
