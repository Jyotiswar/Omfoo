#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    struct Trip {
        int value, a, b;
        bool operator<(const Trip& other) const {
            if (value == other.value) {
                if (a == other.a)
                    return b > other.b;
                return a > other.a;
            }
            return value > other.value;
        }
    };

    std::vector<int> maxCombinations(int N, int K, std::vector<int>& A, std::vector<int>& B) {
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        std::set<Trip> st;
        st.insert({A.back() + B.back(), N - 1, N - 1});
        std::vector<int> out;
        while (K--) {
            int value = st.begin()->value;
            int a = st.begin()->a;
            int b = st.begin()->b;
            st.erase(st.begin());
            out.push_back(value);
            if (a > 0)
                st.insert({A[a - 1] + B[b], a - 1, b});
            if (b > 0)
                st.insert({A[a] + B[b - 1], a, b - 1});
        }
        return out;
    }
};

int main() {
    Solution solution;

    // Test the maxCombinations function with different values
    int N = 3;
    int K = 3;
    std::vector<int> A = {1, 2, 3};
    std::vector<int> B = {4, 5, 6};
    std::vector<int> result = solution.maxCombinations(N, K, A, B);

    std::cout << "Max Combinations for N=" << N << ", K=" << K << ":" << std::endl;
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
