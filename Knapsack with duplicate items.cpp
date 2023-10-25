#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};

int main() {
    int N, W;
    cout << "Enter the number of items (N): ";
    cin >> N;
    cout << "Enter the maximum weight capacity (W): ";
    cin >> W;

    int val[N], wt[N];
    cout << "Enter the values of items: ";
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    cout << "Enter the weights of items: ";
    for (int i = 0; i < N; i++) {
        cin >> wt[i];
    }

    Solution solution;
    int result = solution.knapSack(N, W, val, wt);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
