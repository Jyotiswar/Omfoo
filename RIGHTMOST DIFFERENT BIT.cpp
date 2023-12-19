#include <iostream>

class Solution {
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n) {
        for (int i = 0; i < 32; i++) {
            int x = (m >> i) & 1;
            int y = (n >> i) & 1;

            if (x != y)
                return i + 1;
        }

        return -1;
    }
};

int main() {
    Solution solution;

    int m, n;
    std::cout << "Enter the values for m and n: ";
    std::cin >> m >> n;

    int result = solution.posOfRightMostDiffBit(m, n);

    if (result != -1)
        std::cout << "Position of the rightmost different bit: " << result << std::endl;
    else
        std::cout << "No different bit found." << std::endl;

    return 0;
}
