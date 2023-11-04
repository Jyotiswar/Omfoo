#include <iostream>
using namespace std;

class Solution {
public:
    int transitionPoint(int arr[], int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;

            if (arr[m] < 1)
                l = m + 1;
            else
                r = m;
        }

        return arr[l] ? l : -1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (0s and 1s): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = sol.transitionPoint(arr, n);

    if (result != -1) {
        cout << "The transition point is at index " << result << endl;
    } else {
        cout << "There is no transition point in the array." << endl;
    }

    return 0;
}
