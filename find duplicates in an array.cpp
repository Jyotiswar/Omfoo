#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> duplicates(int arr[], int n) {
        int cnt[n] = {0};
        for (int i = 0; i < n; ++i)
            ++cnt[arr[i];

        std::vector<int> out;
        for (int i = 0; i < n; ++i)
            if (cnt[i] > 1)
                out.push_back(i);

        if (out.size())
            return out;

        return {-1};
    }
};

int main() {
    Solution solution;

    // Test the duplicates function with different arrays and values of n
    int arr1[] = {1, 2, 3, 3, 2, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::vector<int> result1 = solution.duplicates(arr1, n1);

    if (result1.size() > 0) {
        std::cout << "Duplicates in Test Case 1: ";
        for (int val : result1) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No duplicates found in Test Case 1." << std::endl;
    }

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::vector<int> result2 = solution.duplicates(arr2, n2);

    if (result2.size() > 0) {
        std::cout << "Duplicates in Test Case 2: ";
        for (int val : result2) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No duplicates found in Test Case 2." << std::endl;
    }

    return 0;
}
