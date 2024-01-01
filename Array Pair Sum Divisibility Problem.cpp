#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if (nums.size() % 2 != 0)
            return false;

        vector<int> cnt(k, 0);

        for (auto i : nums)
            ++cnt[i % k];

        int l = 1, r = k - 1;

        while (l < r) {
            if (cnt[l] != cnt[r])
                return false;
            ++l;
            --r;
        }

        if ((l == r && cnt[l] % 2 != 0) || cnt[0] % 2 != 0)
            return false;

        return true;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {9, 7, 5, 3};
    int k = 6;

    bool result = solution.canPair(nums, k);

    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}
