#include <iostream>

class Solution {
public:
    std::string add(std::string num1, std::string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        std::string res;

        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
            --j;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --j;
        }
        if (carry)
            res += carry + '0';
            
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    bool solve(std::string& s, int i, int j, int k) {
        std::string num1 = s.substr(i, j - i);
        std::string num2 = s.substr(j, k - j);
        std::string sum = add(num1, num2);

        int n = sum.size();
        int len = k + n;

        if (len > s.size())
            return false;

        std::string currSum = s.substr(k, n);

        if (currSum != sum)
            return false;
        if (len == s.size())
            return true;
        return solve(s, j, k, len);
    }

    bool isSumString(std::string& s) {
        int n = s.size();
    
        for (int j = 1; j < n; ++j) 
            for (int k = j + 1; k < n; ++k) 
                if (solve(s, 0, j, k))
                    return true;

        return false;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::string testString1 = "3142";
    std::string testString2 = "1235813";

    std::cout << "Is \"" << testString1 << "\" a sum string? " << solution.isSumString(testString1) << std::endl;
    std::cout << "Is \"" << testString2 << "\" a sum string? " << solution.isSumString(testString2) << std::endl;

    return 0;
}
