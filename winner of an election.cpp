
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> winner(string arr[], int n) {
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i)
            ++mp[arr[i]];

        string out;
        int cnt = 0;
        for (auto i : mp) {
            if (cnt < i.second) {
                cnt = i.second;
                out = i.first;
            } else if (cnt == i.second) {
                if (out > i.first)
                    out = i.first;
            }
        }
        return {out, to_string(cnt)};
    }
};

int main() {
    // Example usage
    int n = 5;
    string arr[] = {"Alice", "Bob", "Alice", "Charlie", "Bob"};

    Solution solution;
    vector<string> result = solution.winner(arr, n);

    // Displaying the result
    cout << "Winner: " << result[0] << ", Count: " << result[1] << endl;

    return 0;
}
```

Now, you can compile and run this code to see the result. Adjust the input data as needed.