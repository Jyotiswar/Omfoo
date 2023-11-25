#include <iostream>

class Solution {
public:
    void shuffleArray(int arr[], int n) {
        int offset = 1e5;
        for (int i = 0; i < n / 2; ++i) {
            arr[i * 2] += (arr[i] % offset) * offset;
            arr[i * 2 + 1] += (arr[n / 2 + i] % offset) * offset;
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = arr[i] / offset;
        }
    }
};

int main() {
    Solution solution;

    // Example usage:
    const int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    solution.shuffleArray(arr, n);

    std::cout << "Shuffled array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
