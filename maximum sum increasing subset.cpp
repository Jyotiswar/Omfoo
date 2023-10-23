#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumIS(int arr[], int n) {
        vector<int> dp(arr, arr + n);

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);

        int out = 0;
        for (auto i : dp)
            out = max(out, i);
        return out;
    }
};

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    int result = sol.maxSumIS(arr, n);

    cout << "The maximum sum increasing subsequence is: " << result << endl;

    return 0;
}
