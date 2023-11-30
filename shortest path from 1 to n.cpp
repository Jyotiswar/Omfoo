#include <iostream>

using namespace std;

class Solution {
public:
    int minimumStep(int n) {
        int cnt = 0;
        while (n > 1) {
            if (n % 3 == 0)
                n /= 3;
            else
                n -= 1;
            ++cnt;
        }
        return cnt;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the minimumStep function with an example value
    int result = solution.minimumStep(10);

    // Display the result
    cout << "Minimum steps for n = 10: " << result << endl;

    return 0;
}
