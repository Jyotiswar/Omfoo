#include <iostream>

using namespace std;

class Solution {
public:
    int nthPoint(int n) {
        long long num1 = 1, num2 = 1, mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            long long a = (num1 + num2) % mod;
            num1 = num2;
            num2 = a;
        }
        return static_cast<int>(num2);
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the nthPoint function with an example value
    int n = 5;
    int result = solution.nthPoint(n);

    // Display the result
    cout << "The nth point: " << result << endl;

    return 0;
}
