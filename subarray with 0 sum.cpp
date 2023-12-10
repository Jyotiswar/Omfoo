#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        int sum = 0;
        unordered_set<int> s;
        s.insert(0);

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (s.find(sum) != s.end())
                return true;
            s.insert(sum);
        }

        return false;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test the subArrayExists function with an example array
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool result = solution.subArrayExists(arr, n);

    // Display the result
    cout << "Subarray with zero sum " << (result ? "exists." : "does not exist.") << endl;

    return 0;
}
