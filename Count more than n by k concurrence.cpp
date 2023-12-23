#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int countOccurence(int arr[], int n, int k) {
        map<int, int> mp;
        int minCnt = n / k;
        for (int i = 0; i < n; ++i)
            ++mp[arr[i]];

        int out = 0;
        for (auto i : mp)
            if (i.second > minCnt)
                ++out;

        return out;
    }
};

int main() {
    Solution solution;

    // Example usage
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = solution.countOccurence(arr, n, k);

    cout << "Number of elements occurring more than " << n / k << " times: " << result << endl;

    return 0;
}
