#include <iostream>
using namespace std;

class Solution {
public:
    int isPossible(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i] % 3;
        return sum % 3 == 0;
    }
};

int main() {
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Solution solution;
    if (solution.isPossible(N, arr)) {
        cout << "The sum of the elements is divisible by 3." << endl;
    } else {
        cout << "The sum of the elements is not divisible by 3." << endl;
    }

    return 0;
}
