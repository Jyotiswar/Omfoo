#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto i : nums)
            ++mp[i];

        priority_queue<pair<int, int>> pq;

        for (auto itr : mp) {
            pq.push({itr.second, itr.first});
        }

        vector<int> out;
        while (!pq.empty() && k--) {
            out.push_back(pq.top().second);
            pq.pop();
        }

        return out;
    }
};

int main() {
    Solution sol;
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> nums;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> result = sol.topK(nums, k);

    cout << "Top " << k << " frequent elements are: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
