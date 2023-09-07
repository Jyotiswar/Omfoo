#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int MOD = 100000;
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end)
            return 0;

        int n = arr.size();
        vector<int> dp(MOD, -1);

        dp[start] = 0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                long long next = 1LL * current * arr[i] % MOD;

                if (dp[next] == -1) {
                    dp[next] = dp[current] + 1;
                    q.push(next);

                    if (next == end) {
                        return dp[next];
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;

    // Define input data
    vector<int> arr = {2, 3, 5};
    int start = 2;
    int end = 10;

    // Call the minimumMultiplications function
    int result = solution.minimumMultiplications(arr, start, end);

    if (result != -1) {
        cout << "Minimum multiplications required: " << result << endl;
    } else {
        cout << "No valid sequence of multiplications found." << endl;
    }

    return 0;
}
