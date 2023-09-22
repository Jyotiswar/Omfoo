#include <iostream>
#include <vector>

class Solution {
public:
    int lower_bound(int arr[], int n, int x) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] >= x)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }

    int upper_bound(int arr[], int n, int x) {
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > x)
                r = m;
            else
                l = m + 1;
        }
        return r - 1;
    }

    std::vector<int> find(int arr[], int n, int x) {
        int firstOccur = lower_bound(arr, n, x);
        if (arr[firstOccur] != x)
            return {-1, -1};

        int lastOccur = upper_bound(arr, n, x);
        return {firstOccur, lastOccur};
    }
};

int main() {
    Solution solution;

    // Test the find function with different arrays and values of n and x
    int arr1[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x1 = 4;
    std::vector<int> result1 = solution.find(arr1, n1, x1);
    std::cout << "Indices of " << x1 << ": " << result1[0] << " - " << result1[1] << std::endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int x2 = 6;
    std::vector<int> result2 = solution.find(arr2, n2, x2);
    std::cout << "Indices of " << x2 << ": " << result2[0] << " - " << result2[1] << std::endl;

    return 0;
}
