#include <iostream>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(int arr[], int n) {
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j]) {
                arr[i++] = arr[j];
            }
        }

        for (; i < n; ++i) {
            arr[i] = 0;
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sol.pushZerosToEnd(arr, n);

    cout << "Array after pushing zeros to the end: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
