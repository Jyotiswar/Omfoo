#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> rotate(int n, int d) {
        int mask_16 = (1 << 16) - 1;
        d = d % 16;

        std::vector<int> out(2);
        out[0] = (n << d | (n >> (16 - d)));
        out[0] = out[0] & mask_16;

        out[1] = (n >> d | (n << (16 - d)));
        out[1] = out[1] & mask_16;

        return out;
    }
};

int main() {
    Solution solution;

    // Test the rotate function with different values of n and d
    int n1 = 65535; // Binary: 1111111111111111
    int d1 = 4;
    std::vector<int> result1 = solution.rotate(n1, d1);
    std::cout << "Rotated left: " << result1[0] << ", Rotated right: " << result1[1] << std::endl;

    int n2 = 4378; // Binary: 0001000101011010
    int d2 = 7;
    std::vector<int> result2 = solution.rotate(n2, d2);
    std::cout << "Rotated left: " << result2[0] << ", Rotated right: " << result2[1] << std::endl;

    return 0;
}
