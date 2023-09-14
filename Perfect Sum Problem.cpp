#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int arr[], int n, int i, int sum, std::vector<std::vector<int>>& dp) {
        if (sum == 0)
            return 1;

        if (i >= n)
            return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long t = 0;
        long long nt = solve(arr, n, i + 1, sum, dp);

        if (sum >= arr[i])
            t = solve(arr, n, i + 1, sum - arr[i], dp);

        return dp[i][sum] = (t + nt) % mod;
    }

    int perfectSum(int arr[], int n, int sum) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(sum + 1, -1));
        std::sort(arr, arr + n);
        int out = solve(arr, n, 0, sum, dp);
        return out;
    }
};

int main() {
    Solution solution;

    // Test the perfectSum function with different arrays and target sums
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int sum1 = 5;
    int result1 = solution.perfectSum(arr1, n1, sum1);
    std::cout << "Result 1: " << result1 << std::endl;

    int arr2[] = {2, 2, 3, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int sum2 = 6;
    int result2 = solution.perfectSum(arr2, n2, sum2);
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}
