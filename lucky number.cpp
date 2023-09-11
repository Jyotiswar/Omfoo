#include <iostream>

class Solution {
public:
    bool isLucky(int n) {
        int cnt = 2;
        while (cnt <= n) {
            if (n % cnt == 0)
                return false;

            n -= n / cnt;
            ++cnt;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test the isLucky function with various numbers
    int testNumbers[] = {5, 7, 13, 20, 21};
    for (int num : testNumbers) {
        bool result = solution.isLucky(num);
        std::cout << num << " is lucky: " << (result ? "true" : "false") << std::endl;
    }

    return 0;
}
