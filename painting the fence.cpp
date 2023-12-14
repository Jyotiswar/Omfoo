#include <iostream>

using namespace std;

class Solution {
public:
    long long countWays(int n, int k) {
        long mod = 1e9 + 7;
        long same = 0;
        long diff = k;
        long total = same + diff;

        for (int i = 2; i <= n; ++i) {
            same = diff * 1;
            diff = (total * (k - 1)) % mod;
            total = same + diff;
        }
        return total % mod;
    }
};

int main() {
    Solution solution;

    int n, k;
    cout << "Enter the values of n and k separated by a space: ";
    cin >> n >> k;

    long long result = solution.countWays(n, k);

    cout << "The count of ways for n = " << n << " and k = " << k << " is: " << result << endl;

    return 0;
}
