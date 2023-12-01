#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> arr, leaf;

    void inorder(Node* node) {
        if (!node)
            return;

        inorder(node->left);
        arr.push_back(node->data);
        if (!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }

    bool isDeadEnd(Node* root) {
        arr = {0}; // Initialize with a 0 value to handle the edge case of root being 1.
        leaf = {};
        inorder(root);

        int j = 0;
        for (int i = 1; i < arr.size() && j < leaf.size(); ++i) {
            if (arr[i] == leaf[j]) {
                if (arr[i - 1] == leaf[j] - 1 && arr[i + 1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }

        return false;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create a sample binary search tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(9);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);

    // Check if the tree has a dead end
    bool hasDeadEnd = solution.isDeadEnd(root);

    if (hasDeadEnd) {
        cout << "The tree has a dead end.\n";
    } else {
        cout << "The tree does not have a dead end.\n";
    }

    // Clean up memory (assuming you're not using smart pointers or a memory management library)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
