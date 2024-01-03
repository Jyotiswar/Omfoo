#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestSubstring(string S) {
        vector<int> pos(3, -1);
        int out = INT_MAX;

        for(int i = 0; i < S.size(); ++i) {
            pos[S[i] - '0'] = i;

            int nin = INT_MAX, nax = 0;
            for(auto it: pos) {
                nin = min(nin, it);
                nax = max(nax, it);
            }    

            if(nin != -1)
                out = min(out, nax - nin + 1);
        }

        return out == INT_MAX ? -1 : out;
    }
};

int main() {
    Solution sol;
    string input = "210120";
    int result = sol.smallestSubstring(input);
    cout << "Length of the smallest substring: " << result << endl;

    return 0;
}
