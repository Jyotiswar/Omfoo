#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};

    int dfs(vector<vector<int>>& grid, int i, int j, int& id, int& n) {
        grid[i][j] = id;
        int c = 1;
        for (int d = 0; d < 4; ++d) {
            int x = dx[d] + i;
            int y = dy[d] + j;
            if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1)
                c += dfs(grid, x, y, id, n);
        }
        return c;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int out = 0;
        unordered_map<int, int> mp;
        int id = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++id;
                    int c = dfs(grid, i, j, id, n);
                    mp[id] = c;
                    out = max(out, c);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int c = 1;
                    set<int> st;
                    for (int d = 0; d < 4; ++d) {
                        int x = dx[d] + i;
                        int y = dy[d] + j;
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1)
                            st.insert(grid[x][y]);
                    }
                    for (auto i : st)
                        c += mp[i];
                    out = max(out, c);
                }
            }
        }
        return out;
    }
};

int main() {
    Solution solution;

    // Create a sample grid
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1}
    };

    int largestIslandSize = solution.largestIsland(grid);

    cout << "Size of the largest island: " << largestIslandSize << endl;

    return 0;
}
