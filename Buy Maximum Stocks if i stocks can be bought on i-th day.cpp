#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
            v.push_back({price[i], i + 1});

        sort(v.begin(), v.end());

        int out = 0;

        for (auto i : v) {
            int maxBuy = min(k / i.first, i.second);
            out += maxBuy;
            k -= i.first * maxBuy;
        }
        return out;
    }
};

int main() {
    Solution sol;

    // Example input
    int n = 5;
    int k = 20;
    int price[] = {4, 10, 3, 5, 8};

    // Calculate and print the result
    int result = sol.buyMaximumProducts(n, k, price);
    cout << "Maximum number of products that can be bought: " << result << endl;

    return 0;
}
