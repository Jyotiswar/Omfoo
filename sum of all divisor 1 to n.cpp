#include <iostream>
using namespace std;

class Solution {
public:
    long long sumOfDivisors(int N) {
        long long out = 0;
        for (int i = 1; i <= N; ++i) {
            out += (N / i) * i;
        }
        return out;
    }
};

int main() {
    int N;
    cout << "Enter a number (N): ";
    cin >> N;

    Solution solution;
    long long result = solution.sumOfDivisors(N);

    cout << "Sum of divisors for " << N << " is: " << result << endl;

    return 0;
}
