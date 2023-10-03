#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string colName(long long int n) {
        std::string out;
        std::vector<char> code(26);
        for (int i = 1; i < 26; ++i)
            code[i] = (char)('A' + i - 1);
        code[0] = 'Z';

        while (n) {
            out += code[n % 26];
            if (n % 26 == 0)
                --n;
            n /= 26;
        }

        std::reverse(out.begin(), out.end());
        return out;
    }
};

int main() {
    Solution solution;

    // Test the colName function with a sample input
    long long int n = 701; // Example input

    std::string result = solution.colName(n);

    std::cout << "Column Name: " << result << std::endl;

    return 0;
}
