#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    std::vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        std::vector<int> out;
        int nin = INT_MAX;

        int a = 0, b = m - 1;
        while (a < n && b >= 0) {
            int sum = arr[a] + brr[b];
            if (std::abs(sum - x) < nin) {
                out = {arr[a], brr[b]};
                nin = std::abs(sum - x);
            }
            if (sum > x)
                --b;
            else
                ++a;
        }
        return out;
    }
};

int main() {
    Solution solution;

    // Test the printClosest function with different arrays and values
    int n = 4;
    int m = 4;
    int x = 10;
    int arr[] = {1, 4, 5, 7};
    int brr[] = {10, 20, 30, 40};
    std::vector<int> result = solution.printClosest(arr, brr, n, m, x);

    std::cout << "Closest pair to " << x << ": [" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}
