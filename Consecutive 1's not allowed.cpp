#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    long long countStrings(int n) {
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    long long result = solution.countStrings(n);

    cout << "The count of strings for length " << n << " is: " << result << endl;

    return 0;
}
