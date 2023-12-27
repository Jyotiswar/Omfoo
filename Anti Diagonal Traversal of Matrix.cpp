#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void fill(int i, int j, vector<vector<int>>& mat, vector<int>& out) {
        while (i < mat.size() && j >= 0) {
            out.push_back(mat[i][j]);
            ++i;
            --j;
        }
    }

    vector<int> antiDiagonalPattern(vector<vector<int>>& mat) {
        vector<int> out;
        int n = mat.size();
        for (int j = 0; j < n; ++j)
            fill(0, j, mat, out);

        for (int i = 1; i < n; ++i)
            fill(i, n - 1, mat, out);

        return out;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> result = solution.antiDiagonalPattern(matrix);

    cout << "Anti-Diagonal Pattern: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
