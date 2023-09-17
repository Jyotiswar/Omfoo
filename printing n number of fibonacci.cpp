#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<long long> printFibb(int n) {
        if (n <= 2)
            return std::vector<long long>(n, 1);

        std::vector<long long> out(n);
        out[0] = out[1] = 1;
        for (int i = 2; i < n; ++i) {
            out[i] = out[i - 1] + out[i - 2];
        }
        return out;
    }
};

int main() {
    Solution solution;

    // Test the printFibb function with different values of n
    int n1 = 5;
    std::vector<long long> result1 = solution.printFibb(n1);
    std::cout << "Fibonacci sequence for n = " << n1 << ": ";
    for (long long num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int n2 = 8;
    std::vector<long long> result2 = solution.printFibb(n2);
    std::cout << "Fibonacci sequence for n = " << n2 << ": ";
    for (long long num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
