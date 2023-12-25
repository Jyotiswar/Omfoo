#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> &matrix, int n)
    {
        if (n == 1)
            return matrix[0][0];

        int ans = 0;

        // Traverse all columns of 0th row
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> second(n - 1, vector<int>(n - 1));

            // Traverse all rows of the second matrix
            for (int j = 1; j < n; j++)
            {
                int x = 0;

                // Traverse all columns of the second matrix
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        continue;

                    second[j - 1][x++] = matrix[j][k];
                }
            }

            ans += matrix[0][i] * determinantOfMatrix(second, n - 1) * ((i & 1) ? -1 : 1);
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    int n = matrix.size();

    // Call the determinantOfMatrix function
    int determinant = solution.determinantOfMatrix(matrix, n);

    // Print the result
    cout << "Determinant: " << determinant << endl;

    return 0;
}
