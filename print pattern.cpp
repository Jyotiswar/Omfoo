#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pattern(int N) {
        if (N <= 0)
            return {N};
            
        int toggle = -5;
        int c = N;
        vector<int> out;
        
        do {
            out.push_back(c);
            c += toggle;
            if (c <= 0)
                toggle = -toggle;
        } while (c != N);
        
        out.push_back(N);
        return out;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the pattern function with an example value
    int N = 10;
    vector<int> result = solution.pattern(N);

    // Display the result
    cout << "Pattern for N = " << N << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
