#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string printMinNumberForPattern(string S) {
        vector<pair<char, int>> col;
        char curr = S[0];
        int c = (S[0] == 'I');

        for (auto i : S) {
            if (i == curr)
                ++c;
            else {
                col.push_back({ curr, c });
                c = 1;
                curr = i;
            }
        }
        if (S.back() == 'I')
            ++c;
        col.push_back({ curr, c });

        string out;
        c = 1;
        for (auto i : col) {
            char op = i.first;
            int cnt = i.second + (op == 'D' ? 1 : -1);
            string temp;
            while (cnt--) {
                temp += (char)('0' + c++);
            }
            if (op == 'D')
                reverse(temp.begin(), temp.end());
            out += temp;
        }
        return out;
    }
};

int main() {
    Solution sol;
    string S;
    cout << "Enter the pattern string (containing 'I' and 'D'): ";
    cin >> S;

    string result = sol.printMinNumberForPattern(S);

    cout << "Minimum number for the given pattern: " << result << endl;

    return 0;
}
