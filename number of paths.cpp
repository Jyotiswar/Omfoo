#include <iostream>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    long long modInv(long long a, long long b) {
        return 1 < a ? b - modInv(b % a, a) * b / a : 1;
    }

    long long numberOfPaths(int m, int n) {
        long long out = 1;

        for (int i = 0; i < m - 1; i++) {
            long long inverse = modInv(i + 1, mod);
            out = (out * (i + n)) % mod;
            out = (out * inverse) % mod;
        }

        return out;
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    Solution solution;
    long long result = solution.numberOfPaths(m, n);

    cout << "Number of paths from top-left to bottom-right: " << result << endl;

    return 0;
}
