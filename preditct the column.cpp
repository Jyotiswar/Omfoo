#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int columnWithMaxZeros(vector<vector<int>>& arr, int n) {
        int maxZeros = 0;
        int columnIdx = -1;

        for (int j = 0; j < n; j++) {
            int zerosCount = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i][j] == 0) {
                    zerosCount++;
                }
            }

            if (zerosCount > maxZeros) {
                maxZeros = zerosCount;
                columnIdx = j;
            }
        }

        return columnIdx;
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

    int result = sol.columnWithMaxZeros(matrix, n);

    if (result != -1) {
        cout << "The column with the most zeros is at index " << result << endl;
    } else {
        cout << "No columns with zeros found." << endl;
    }

    return 0;
}
