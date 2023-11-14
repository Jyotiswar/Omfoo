#include <iostream>

class Solution {
public:
    bool areRotations(std::string s1, std::string s2) {
        std::string s = s1 + s1;
        return s.find(s2) != std::string::npos;
    }
};

int main() {
    Solution solution;

    // Example usage
    std::string str1 = "waterbottle";
    std::string str2 = "bottlewater";

    if (solution.areRotations(str1, str2)) {
        std::cout << "The strings are rotations of each other.\n";
    } else {
        std::cout << "The strings are not rotations of each other.\n";
    }

    return 0;
}
