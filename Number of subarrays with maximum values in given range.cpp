#include <iostream>

using namespace std;

class Solution {
public:
    long countSubarrays(int a[], int n, int L, int R) {
        long out = 0, range = 0;
        long i = 0;

        for (long j = 0; j < n; ++j) {
            if (a[j] >= L && a[j] <= R)
                range = j - i + 1;
            else if (a[j] > R)
                range = 0, i = j + 1;

            out += range;
        }

        return out;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the countSubarrays function with an example array and range
    int arr[] = {2, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int L = 2, R = 3;

    long result = solution.countSubarrays(arr, n, L, R);

    // Display the result
    cout << "Number of subarrays with sum in the range [" << L << ", " << R << "]: " << result << endl;

    return 0;
}
