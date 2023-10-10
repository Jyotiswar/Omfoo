#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> out;

    void trace(Node* node, int k) {
        if (!node || k < 0)
            return;

        if (k == 0) {
            out.push_back(node->data);
            return;
        }

        trace(node->left, k - 1);
        trace(node->right, k - 1);
    }

    int findDist(Node* node, int target, int k) {
        if (!node)
            return INT_MIN;

        if (node->data == target) {
            trace(node, k);
            return k - 1;
        }

        int fromLeft = findDist(node->left, target, k);
        if (fromLeft != INT_MIN) {
            if (fromLeft == 0)
                out.push_back(node->data);
            else if (fromLeft > 0)
                trace(node->right, fromLeft - 1);

            return fromLeft - 1;
        }

        int fromRight = findDist(node->right, target, k);
        if (fromRight != INT_MIN) {
            if (fromRight == 0)
                out.push_back(node->data);
            else if (fromRight > 0)
                trace(node->left, fromRight - 1);

            return fromRight - 1;
        }

        return INT_MIN;
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        out = vector<int>(0);
        findDist(root, target, k);
        sort(out.begin(), out.end());
        return out;
    }
};

int main() {
    // Create a binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    Solution solution;
    int target = 5;
    int k = 2;
    vector<int> result = solution.KDistanceNodes(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (you should free memory properly in a real program)
    // Perform post-order traversal to delete nodes
    // (delete right, delete left, then delete the node itself)
    while (root) {
        Node* left = root->left;
        Node* right = root->right;
        delete root;
        root = nullptr;
        root = left;
        if (!root)
            root = right;
    }

    return 0;
}
