#include <iostream>
#include <vector>

class Solution {
public:
    int FindMaxSum(int arr[], int n) {
        std::vector<int> dp(n, 0);
        int out = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= 2)
                dp[i] = dp[i - 2];
            if (i >= 3)
                dp[i] = std::max(dp[i], dp[i - 3]);

            dp[i] += arr[i];
            out = std::max(out, dp[i]);
        }

        return out;
    }
};

int main() {
    Solution solution;

    // Test the FindMaxSum function with different arrays and values of n
    int arr1[] = {5, 1, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = solution.FindMaxSum(arr1, n1);
    std::cout << "Max Sum for Test Case 1: " << result1 << std::endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = solution.FindMaxSum(arr2, n2);
    std::cout << "Max Sum for Test Case 2: " << result2 << std::endl;

    return 0;
}
