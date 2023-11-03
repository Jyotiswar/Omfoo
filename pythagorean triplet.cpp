#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool checkTriplet(int arr[], int n) {
        std::unordered_set<int> s;

        for (int i = 0; i < n; ++i)
            s.insert(arr[i] * arr[i]);

        for (auto a : s) {
            for (auto b : s) {
                if (s.find(a + b) != s.end())
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int arr[] = {3, 1, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution solution;
    bool result = solution.checkTriplet(arr, n);

    if (result) {
        std::cout << "There is a Pythagorean triplet in the array." << std::endl;
    } else {
        std::cout << "There is no Pythagorean triplet in the array." << std::endl;
    }

    return 0;
}
