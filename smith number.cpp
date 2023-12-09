#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool is_prime(int n) {
        if (n == 1)
            return false;

        for (int i = 2; i <= sqrt(n); ++i)
            if (n % i == 0)
                return false;

        return true;
    }

    int sumOfDigits(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int sumOfPrimeFactor(int n) {
        int f = 1;
        int sum = 0;
        while (n > 1) {
            ++f;
            if (!is_prime(f))
                continue;

            while (n % f == 0) {
                sum += sumOfDigits(f);
                n /= f;
            }
        }
        return sum;
    }

    int smithNum(int n) {
        if (is_prime(n))
            return 0;

        return sumOfPrimeFactor(n) == sumOfDigits(n);
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the smithNum function with an example value
    int number = 666;
    bool result = solution.smithNum(number);

    // Display the result
    cout << number << " is a Smith Number: " << (result ? "Yes" : "No") << endl;

    return 0;
}
