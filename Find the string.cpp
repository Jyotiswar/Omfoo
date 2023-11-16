#include <iostream>
#include <unordered_set>

class Solution {
public:
    void dfs(int k, std::string prev, std::unordered_set<std::string> &seen, std::string &edges) {
        for (char i = '0'; i <= ('0' + k - 1); i++) {
            std::string cur = prev + i;
            if (seen.find(cur) == seen.end()) {
                seen.insert(cur);
                dfs(k, cur.substr(1), seen, edges);
                edges += i;
            }
        }
    }

    std::string findString(int n, int k) {
        std::unordered_set<std::string> seen;
        std::string startingNode = std::string(n - 1, '0');
        std::string edges;
        dfs(k, startingNode, seen, edges);

        std::string ret = edges + startingNode;
        return ret;
    }
};

int main() {
    Solution solution;

    // Example: n=4, k=3
    int n = 4;
    int k = 3;

    std::string result = solution.findString(n, k);

    // Display the result
    std::cout << "Resulting String: " << result << std::endl;

    return 0;
}
