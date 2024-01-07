#include <iostream>

class Solution {
public:
    int splitArray(int arr[], int N, int K) {
        int low = 0;
        int high = 0;

        for (int i = 0; i < N; i++)
            high += arr[i], low = std::max(low, arr[i] - 1);

        while (low < high - 1) {
            int mid = low + (high - low) / 2;

            auto check = [&]() -> bool {
                int cuts = 0;

                int sum = 0;

                for (int i = 0; i < N; i++) {
                    if (sum + arr[i] > mid) {
                        ++cuts;
                        sum = arr[i];
                    } else {
                        sum += arr[i];
                    }
                }

                return cuts < K;
            };

            if (check())
                high = mid;
            else
                low = mid;
        }

        return high;
    }
};

int main() {
    // Example usage:
    int arr[] = {1, 2, 3, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    Solution solution;
    int result = solution.splitArray(arr, N, K);

    std::cout << "Minimum sum of maximum parts: " << result << std::endl;

    return 0;
}
