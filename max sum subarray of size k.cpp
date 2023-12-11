#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        long out = 0;
        long sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += Arr[i];
            if (i >= K)
                sum -= Arr[i - K];

            out = max(out, sum);
        }
        return out;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the maximumSumSubarray function with an example vector
    vector<int> Arr = {1, 2, 3, -10, 5};
    int K = 3;
    int N = Arr.size();

    long result = solution.maximumSumSubarray(K, Arr, N);

    // Display the result
    cout << "Maximum sum of subarray with size " << K << ": " << result << endl;

    return 0;
}
