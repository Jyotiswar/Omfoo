#include <iostream>
using namespace std;

class Solution {
public:
    long long int sumXOR(int arr[], int n) {
        long long int out = 0;
        for (int i = 0; i < 32; ++i) {
            long long int ones = 0;
            int mask = 1 << i;
            for (int j = 0; j < n; ++j) {
                if ((arr[j] & mask) != 0) {
                    ones++;
                }
            }
            out += (ones * (n - ones) * mask);
        }
        return out;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long int result = sol.sumXOR(arr, n);

    cout << "Result of sumXOR: " << result << endl;

    return 0;
}
