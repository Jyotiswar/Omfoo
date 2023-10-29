#include <iostream>
using namespace std;

class Solution {
public:
    bool checkKthBit(int n, int k) {
        int mask = 1 << k;
        return n & mask;
    }
};

int main() {
    Solution sol;
    int n, k;

    cout << "Enter an integer (n): ";
    cin >> n;
    cout << "Enter the bit position (k): ";
    cin >> k;

    if (sol.checkKthBit(n, k)) {
        cout << "The " << k << "th bit of " << n << " is set (1)." << endl;
    } else {
        cout << "The " << k << "th bit of " << n << " is not set (0)." << endl;
    }

    return 0;
}
