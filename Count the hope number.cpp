#include <iostream>
#include <vector>

class Solution {
public:
    int mod = 1e9 + 7;

    long long solve(int n, int i, std::vector<long long>& dp) {
        if (i == n)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long cnt = 0;
        for (int d = 1; d <= 3; ++d) {
            if (i + d <= n)
                cnt = (cnt + solve(n, i + d, dp)) % mod;
        }

        return dp[i] = cnt;
    }

    long long countWays(int n) {
        std::vector<long long> dp(n + 1, -1);
        return solve(n, 0, dp);
    }
};

int main() {
    Solution solution;

    // Test the countWays function with different values of n
    int n1 = 4;
    long long result1 = solution.countWays(n1);
    std::cout << "Ways to climb " << n1 << " stairs: " << result1 << std::endl;

    int n2 = 5;
    long long result2 = solution.countWays(n2);
    std::cout << "Ways to climb " << n2 << " stairs: " << result2 << std::endl;

    return 0;
}
