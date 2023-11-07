#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumTriangles(const vector<vector<int>>& matrix, int n) {
        vector<int> out(2, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i <= j)
                    out[0] += matrix[i][j];
                if (i >= j)
                    out[1] += matrix[i][j];
            }
        }
        return out;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = sol.sumTriangles(matrix, n);

    cout << "Sum of upper triangle elements: " << result[0] << endl;
    cout << "Sum of lower triangle elements: " << result[1] << endl;

    return 0;
}
