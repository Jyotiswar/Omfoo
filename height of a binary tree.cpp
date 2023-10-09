#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int height(Node* node) {
        if (!node)
            return 0;
        
        return std::max(height(node->left), height(node->right)) + 1;
    }
};

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Solution solution;
    int treeHeight = solution.height(root);

    std::cout << "The height of the binary tree is: " << treeHeight << std::endl;

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
