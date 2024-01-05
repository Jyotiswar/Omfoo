#include <iostream>

class Solution {
public:
    int mod = 1e9 + 7;

    int TotalWays(int N) {
        long long curr, prev, next;
        curr = prev = 1;
        for (int i = 1; i <= N; ++i) {
            next = (curr + prev) % mod;
            prev = curr;
            curr = next;
        }

        return (curr * curr) % mod;
    }
};

int main() {
    Solution sol;
    int N = 5;
    int result = sol.TotalWays(N);

    std::cout << "Total ways to arrange elements from 1 to " << N << ": " << result << std::endl;

    return 0;
}
