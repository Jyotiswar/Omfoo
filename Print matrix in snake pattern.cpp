#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> snakePattern(vector<vector<int>> matrix) {
        bool toggle = false;
        vector<int> out;
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            if (toggle) {
                for (int j = n - 1; j >= 0; --j) {
                    out.push_back(matrix[i][j]);
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    out.push_back(matrix[i][j]);
                }
            }
            toggle = !toggle;
        }
        return out;
    }
};

int main() {
    // Define the matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the snakePattern function
    vector<int> result = solution.snakePattern(matrix);

    // Print the result
    cout << "Snake Pattern: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
