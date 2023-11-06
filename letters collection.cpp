#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[]) {
        vector<int> out;

        for (int k = 0; k < q; ++k) {
            int sum = 0;
            int hop = queries[k][0];
            int x = queries[k][1];
            int y = queries[k][2];

            for (int i = x - hop; i <= x + hop; ++i) {
                if (i >= 0 && i < n) {
                    if (y - hop >= 0)
                        sum += mat[i][y - hop];
                    if (y + hop < m)
                        sum += mat[i][y + hop];
                }
            }

            for (int i = y - hop + 1; i < y + hop; ++i) {
                if (i >= 0 && i < m) {
                    if (x - hop >= 0)
                        sum += mat[x - hop][i];
                    if (x + hop < n)
                        sum += mat[x + hop][i];
                }
            }

            out.push_back(sum);
        }
        return out;
    }
};

int main() {
    Solution sol;
    int n, m;
    cout << "Enter the number of rows (n) and columns (m) in the matrix: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    int q;
    cout << "Enter the number of queries (q): ";
    cin >> q;

    vector<int> queries[q];
    cout << "Enter the queries (hop x y):" << endl;
    for (int i = 0; i < q; ++i) {
        int hop, x, y;
        cin >> hop >> x >> y;
        queries[i] = {hop, x, y};
    }

    vector<int> result = sol.matrixSum(n, m, mat, q, queries);

    cout << "Results of queries:" << endl;
    for (int i = 0; i < q; ++i) {
        cout << "Query " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}
