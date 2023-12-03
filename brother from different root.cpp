#include <iostream>

class Solution {
public:
    int isRepresentingBST(int arr[], int N) {
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] < arr[i + 1])
                continue;
            else
                return 0;
        }
        return 1;
    }
};

int main() {
    Solution solution;

    // Example usage:
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 2, 4, 5};

    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int N2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "arr1 is representing a BST: " << solution.isRepresentingBST(arr1, N1) << std::endl;
    std::cout << "arr2 is representing a BST: " << solution.isRepresentingBST(arr2, N2) << std::endl;

    return 0;
}
