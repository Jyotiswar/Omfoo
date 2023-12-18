#include <iostream>

using namespace std;

class Solution {
public:
    int gameOfXor(int N, int A[]) {
        if (N % 2 == 0)
            return 0;

        int XOR = 0;
        for (int i = 0; i < N; i += 2)
            XOR ^= A[i];
        return XOR;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the gameOfXor function with an example array
    int N = 5;
    int A[] = {1, 2, 3, 4, 5};

    int result = solution.gameOfXor(N, A);

    // Display the result
    cout << "Result of the game of XOR: " << result << endl;

    return 0;
}
