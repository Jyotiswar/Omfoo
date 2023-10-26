#include <iostream>

class Solution {
public:
    int minOperation(int n) {
        int out = -1;
        while (n) {
            if (n % 2)
                ++out;
            n /= 2;
            ++out;
        }

        return out;
    }
};

int main() {
    Solution sol;
    int n = 42;  // Replace with your desired input value
    int result = sol.minOperation(n);

    std::cout << "Minimum number of operations: " << result << std::endl;

    return 0;
}
