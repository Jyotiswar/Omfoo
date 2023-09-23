#include <iostream>

class Solution {
public:
    int equilibriumPoint(long long a[], int n) {
        long long sum = 0, preSum = 0;
        for (int i = 0; i < n; ++i)
            sum += a[i];

        for (int i = 0; i < n; ++i) {
            sum -= a[i];
            if (sum == preSum)
                return i + 1;
            preSum += a[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Test the equilibriumPoint function with different arrays and values of n
    long long arr1[] = {1, 2, 3, 3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = solution.equilibriumPoint(arr1, n1);
    if (result1 != -1) {
        std::cout << "Equilibrium Point in Test Case 1: " << result1 << " (Value: " << arr1[result1 - 1] << ")" << std::endl;
    } else {
        std::cout << "No equilibrium point found in Test Case 1." << std::endl;
    }

    long long arr2[] = {1, 2, 4, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = solution.equilibriumPoint(arr2, n2);
    if (result2 != -1) {
        std::cout << "Equilibrium Point in Test Case 2: " << result2 << " (Value: " << arr2[result2 - 1] << ")" << std::endl;
    } else {
        std::cout << "No equilibrium point found in Test Case 2." << std::endl;
    }

    return 0;
}
