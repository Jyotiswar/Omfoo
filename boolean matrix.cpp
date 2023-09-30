#include <iostream>
#include <vector>

class Solution {
public:
    void booleanMatrix(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<bool> r(n, false);
        std::vector<bool> c(m, false);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j]) {
                    r[i] = true;
                    c[j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (r[i]) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 1;
                }
            }
        }

        for (int j = 0; j < m; ++j) {
            if (c[j]) {
                for (int i = 0; i < n; ++i) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    Solution solution;

    // Test the booleanMatrix function with a sample matrix
    std::vector<std::vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    std::cout << "Original Matrix:" << std::endl;
    for (const auto &row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    solution.booleanMatrix(matrix);

    std::cout << "Modified Matrix:" << std::endl;
    for (const auto &row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
