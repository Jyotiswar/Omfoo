#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int is_bleak(int n) {
        for (int i = 1; i <= log2(n); ++i) {
            int x = n - i;
            int setBits = __builtin_popcount(x);
            if (setBits + x == n)
                return 0;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number to check if it's bleak: ";
    cin >> n;

    int result = sol.is_bleak(n);

    if (result == 0) {
        cout << n << " is bleak." << endl;
    } else {
        cout << n << " is not bleak." << endl;
    }

    return 0;
}
