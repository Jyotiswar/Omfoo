#include <iostream>

class Solution {
public:
    // Function to check if a given number n is a power of two.
    bool isPowerofTwo(long long n) {
        return n && ((n & (n - 1)) == 0);
    }
};

int main() {
    Solution solution;

    // Test the isPowerofTwo function with different values of n
    long long n1 = 16;
    bool result1 = solution.isPowerofTwo(n1);
    std::cout << n1 << " is a power of two: " << (result1 ? "true" : "false") << std::endl;

    long long n2 = 12;
    bool result2 = solution.isPowerofTwo(n2);
    std::cout << n2 << " is a power of two: " << (result2 ? "true" : "false") << std::endl;

    return 0;
}
