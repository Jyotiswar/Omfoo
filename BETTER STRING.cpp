#include <iostream>
#include <unordered_map>

class Solution {
public:
    int distSubSeq(std::string s) {
        std::unordered_map<char, int> last;
        int count = 1;

        for (auto ch : s) {
            int newCount = 2 * count;

            if (last.find(ch) != last.end())
                newCount -= last[ch];

            last[ch] = count;
            count = newCount;
        }
        return count;
    }

    std::string betterString(std::string s1, std::string s2) {
        int distSubSeq1 = distSubSeq(s1);
        int distSubSeq2 = distSubSeq(s2);

        return distSubSeq2 > distSubSeq1 ? s2 : s1;
    }
};

int main() {
    Solution solution;

    // Example strings
    std::string s1 = "abcabc";
    std::string s2 = "ab";

    // Find and display the better string
    std::string result = solution.betterString(s1, s2);
    std::cout << "Better String: " << result << std::endl;

    return 0;
}
