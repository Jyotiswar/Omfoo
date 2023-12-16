#include <iostream>

long long int countStr(long long int n) {
    long long ans = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (i + j > n)
                continue;

            long long curans = 1;

            long long total = n;
            if (j == 2) {
                curans = (total * (total - 1)) / 2;
                total -= 2;
            } else if (j) {
                curans = total;
                --total;
            }

            if (i)
                curans *= total;

            ans += curans;
        }
    }

    return ans;
}

int main() {
    long long int n;
    std::cout << "Enter a value for n: ";
    std::cin >> n;

    long long int result = countStr(n);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
