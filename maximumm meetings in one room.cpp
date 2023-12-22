#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct meet {
        int start, end, index;
    };

    static bool comp(struct meet& a, struct meet& b) {
        if (a.end == b.end)
            return a.start < b.start;

        return a.end < b.end;
    }

    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
        vector<meet> v;
        vector<int> out;

        for (int i = 0; i < N; ++i)
            v.push_back({S[i], F[i], i + 1});

        sort(v.begin(), v.end(), comp);

        int last = 0;
        for (auto i : v)
            if (last < i.start) {
                last = i.end;
                out.push_back(i.index);
            }

        sort(out.begin(), out.end());
        return out;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};

    vector<int> result = solution.maxMeetings(N, S, F);

    cout << "Selected meetings: ";
    for (int meeting : result) {
        cout << meeting << " ";
    }

    return 0;
}
