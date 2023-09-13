#include <iostream>
#include <string>

class Solution {
public:
    std::string findLargest(int N, int S) {
        if ((!S && N > 1) || N * 9 < S)
            return "-1";
        std::string out;
        for (int i = 0; i < N; ++i) {
            if (S >= 9) {
                out += '9';
                S -= 9;
            } else {
                if (S) {
                    out += std::to_string(S);
                    S = 0;
                } else
                    out += '0';
            }
        }
        return out;
    }
};

int main() {
    Solution solution;

    // Test the findLargest function with different values of N and S
    int testCases[][2] = {
        {3, 21},
        {2, 15},
        {4, 35},
        {1, 5}
    };

    for (auto testCase : testCases) {
        int N = testCase[0];
        int S = testCase[1];
        std::string result = solution.findLargest(N, S);
        std::cout << "N = " << N << ", S = " << S << " => Result: " << result << std::endl;
    }

    return 0;
}
