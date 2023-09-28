#include <iostream>
#include <vector>

class Solution {
public:
    void convertToWave(int n, std::vector<int>& arr) {
        for (int i = 0; i < n - 1; i += 2)
            std::swap(arr[i], arr[i + 1]);
    }
};

int main() {
    Solution solution;

    // Test the convertToWave function with a sample vector
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    solution.convertToWave(n, arr);

    std::cout << "Wave Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
