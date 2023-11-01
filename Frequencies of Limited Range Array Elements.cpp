#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        int offset = P + 1;

        for (auto i : arr) {
            int val = (i - 1) % offset;
            if (val < N) {
                arr[val] += offset;
            }
        }

        for (int i = 0; i < N; ++i) {
            arr[i] /= offset;
        }
    }
};

int main() {
    Solution sol;
    int N, P;
    cout << "Enter the size of the array: ";
    cin >> N;
    cout << "Enter the value of P: ";
    cin >> P;

    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sol.frequencyCount(arr, N, P);

    cout << "Frequency Count: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
