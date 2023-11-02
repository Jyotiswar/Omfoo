#include <iostream>
#include <climits>

class Solution {
public:
    int minDist(int a[], int n, int x, int y) {
        int lastX, lastY, out;
        lastX = lastY = -1;
        out = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (a[i] == x)
                lastX = i;
            if (a[i] == y)
                lastY = i;

            if (lastX != -1 && lastY != -1)
                out = std::min(out, std::abs(lastX - lastY));
        }
        return out == INT_MAX ? -1 : out;
    }
};

int main() {
    int a[] = {1, 2, 3, 4, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 1;
    int y = 5;

    Solution solution;
    int result = solution.minDist(a, n, x, y);

    if (result == -1) {
        std::cout << "Either " << x << " or " << y << " not found in the array." << std::endl;
    } else {
        std::cout << "Minimum distance between " << x << " and " << y << " is: " << result << std::endl;
    }

    return 0;
}

