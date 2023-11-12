#include <iostream>
using namespace std;

class Solution {
public:
    bool isRotated(string s1, string s2) {
        if (s1 == s2.substr(2) + s2.substr(0, 2))
            return true;
        if (s1 == s2.substr(s2.size() - 2) + s2.substr(0, s2.size() - 2))
            return true;

        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    bool result = sol.isRotated(s1, s2);

    if (result) {
        cout << "The strings are rotated versions of each other." << endl;
    } else {
        cout << "The strings are not rotated versions of each other." << endl;
    }

    return 0;
}
