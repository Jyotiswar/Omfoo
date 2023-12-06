#include <iostream>

class Solution {
public: 
    void cntX(int n, int& X, int& cnt) {
        while (n) {
            if (n % 10 == X)
                ++cnt;
            n /= 10;
        }
    }

    int countX(int L, int R, int X) {
        int cnt = 0;

        for (int i = L + 1; i < R; i++)
            cntX(i, X, cnt);

        return cnt;
    }
};

int main() {
    Solution sol;
    
    int L = 10;
    int R = 50;
    int X = 5;

    int result = sol.countX(L, R, X);

    std::cout << "Count of " << X << " between " << L << " and " << R << ": " << result << std::endl;

    return 0;
}
