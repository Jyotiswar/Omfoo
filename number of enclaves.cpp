#include <iostream>
#include <vector>

class Solution {
public:
    int dx[4] = { -1 ,0 ,0, 1};
    int dy[4] = { 0, -1, 1, 0};
    
    void dfs(std::vector<std::vector<int>>& grid, int i, int j, int& n, int& m) {
        grid[i][j] = -1;
        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                dfs(grid, x, y, n, m);
        }
    }
    
    int numberOfEnclaves(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }

        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cnt += (grid[i][j] == 1);
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    // Test the numberOfEnclaves function with a sample grid
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1}
    };

    int result = solution.numberOfEnclaves(grid);

    std::cout << "Number of Enclaves: " << result << std::endl;

    return 0;
}
