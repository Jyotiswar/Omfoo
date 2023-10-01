#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> boundaryTraversal(std::vector<std::vector<int>> matrix, int n, int m) {
        std::vector<int> out;
        int i = 0, j = 0;
        for (; j < m; ++j)
            out.push_back(matrix[i][j]);
        ++i;
        --j;
        if (n > 1) {
            for (; i < n; ++i)
                out.push_back(matrix[i][j]);
            --i;
            --j;
            if (m > 1) {
                for (; j >= 0; --j)
                    out.push_back(matrix[i][j]);
                --i;
                ++j;
                for (; i > 0; --i)
                    out.push_back(matrix[i][j]);
            }
        }
        return out;
    }
};

int main() {
    Solution solution;

    // Test the boundaryTraversal function with a sample matrix
    int n = 4, m = 4;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    std::vector<int> result = solution.boundaryTraversal(matrix, n, m);

    std::cout << "Boundary Elements: ";
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
