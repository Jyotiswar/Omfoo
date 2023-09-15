#include <iostream>
#include <vector>

class Solution {
public:
    bool canPart(int& N, int i, int arr[], int target, std::vector<std::vector<int>>& dp) {
        if (target == 0)
            return true;

        if (i >= N)
            return false;

        if (target >= arr[i]) {
            bool take = canPart(N, i + 1, arr, target - arr[i], dp);
            if (take)
                return dp[i][target] = true;
        }

        bool notTake = canPart(N, i + 1, arr, target, dp);
        return dp[i][target] = notTake;
    }

    bool equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += arr[i];
        }
        if (sum & 1)
            return false;

        int target = sum / 2;
        std::vector<std::vector<int>> dp(N, std::vector<int>(target + 1, -1));
        return canPart(N, 0, arr, target, dp);
    }
};

int main() {
    Solution solution;

    // Test the equalPartition function with different arrays
    int arr1[] = {1, 5, 11, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bool result1 = solution.equalPartition(n1, arr1);
    std::cout << "Result 1: " << (result1 ? "true" : "false") << std::endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bool result2 = solution.equalPartition(n2, arr2);
    std::cout << "Result 2: " << (result2 ? "true" : "false") << std::endl;

    return 0;
}
