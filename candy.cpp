#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> left(N, 1), right(N, 1);

        for (int i = 1; i < N; ++i)
            if (ratings[i] > ratings[i - 1])
                left[i] += left[i - 1];

        for (int i = N - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                right[i] += right[i + 1];

        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += max(left[i], right[i]);

        return sum;
    }
};

int main() {
    Solution solution;

    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> ratings(N);
    cout << "Enter the ratings: ";
    for (int i = 0; i < N; ++i)
        cin >> ratings[i];

    int result = solution.minCandy(N, ratings);

    cout << "Minimum candies required: " << result << endl;

    return 0;
}
