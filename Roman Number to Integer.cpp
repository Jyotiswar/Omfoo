#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToDecimal(std::string &str) {
        std::unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = str.size();

        int out = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[str[i]] < mp[str[i + 1])
                out -= mp[str[i]];
            else
                out += mp[str[i]];
        }

        return out;
    }
};

int main() {
    Solution solution;
    std::string romanNumeral = "MCMXCIV"; // Replace with your desired Roman numeral

    int decimalValue = solution.romanToDecimal(romanNumeral);
    std::cout << "Roman numeral " << romanNumeral << " is equivalent to decimal value: " << decimalValue << std::endl;

    return 0;
}
