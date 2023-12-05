#include <iostream>

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        std::sort(arr, arr + n);
        int out = arr[n - 1] - arr[0];

        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - k >= 0) {
                int nax = std::max(arr[i] + k, arr[n - 1] - k);
                int nin = std::min(arr[i + 1] - k, arr[0] + k);
                out = std::min(out, nax - nin);
            }
        }
        return out;
    }
};

int main() {
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    Solution sol;
    int result = sol.getMinDiff(arr, n, k);

    std::cout << "Minimum Height Difference: " << result << std::endl;

    return 0;
}
