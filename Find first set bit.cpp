#include <iostream>
#include <cmath>

class Solution {
public:
    unsigned int getFirstSetBit(int n) {
        return 1 + log2(n & ~(n - 1));
    }
};

int main() {
    Solution solution;

    // Test the getFirstSetBit function with different values of n
    int n1 = 10;
    unsigned int result1 = solution.getFirstSetBit(n1);
    std::cout << "The position of the first set bit in " << n1 << " is: " << result1 << std::endl;

    int n2 = 16;
    unsigned int result2 = solution.getFirstSetBit(n2);
    std::cout << "The position of the first set bit in " << n2 << " is: " << result2 << std::endl;

    return 0;
}
