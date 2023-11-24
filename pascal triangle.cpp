#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> out(n, 1), prev(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                out[j] = (prev[j] + prev[j - 1]) % mod;
            }
            prev = out;
        }
        return out;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<long long> result = solution.nthRowOfPascalTriangle(n);

    cout << "The nth row of Pascal's Triangle: ";
    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
