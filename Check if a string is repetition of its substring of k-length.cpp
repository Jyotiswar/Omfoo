#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int kSubstrConcat(int n, string s, int k) {
        if (n % k > 0)
            return 0;

        unordered_map<string, int> mp;
        for (int i = 0; i < n / k; ++i)
            ++mp[s.substr(i * k, k)];

        int cnt = 0;
        for (auto i : mp)
            cnt += i.second > 1;

        return (mp.size() <= 2 && cnt <= 1);
    }
};

int main() {
    Solution solution;

    int n = 8;
    string s = "abcabcab";
    int k = 3;

    int result = solution.kSubstrConcat(n, s, k);

    cout << "Result: " << result << endl;

    return 0;
}
