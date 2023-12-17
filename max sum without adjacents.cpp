#include <iostream>

using namespace std;

class Solution {
public:
    // calculate the maximum sum without adjacent
    int findMaxSum(int *arr, int n) {
        int next_0, next_1;
        next_0 = next_1 = 0;

        for (int i = n - 1; i > -1; i--) {
            int cur_0 = max(arr[i] + next_1, next_0);
            int cur_1 = next_0;

            next_0 = cur_0;
            next_1 = cur_1;
        }

        return next_0;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the findMaxSum function with an example array
    int arr[] = {2, 9, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = solution.findMaxSum(arr, n);

    // Display the result
    cout << "Maximum sum without adjacent elements: " << result << endl;

    return 0;
}
