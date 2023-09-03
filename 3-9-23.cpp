#include <iostream>

// Define the structure of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isIsomorphic(Node* root1, Node* root2) {
        if (!root1 && !root2)
            return true;

        if (root1 && root2 && root1->data == root2->data) {
            bool isFlip = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
            bool notFlip = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
            return isFlip || notFlip;
        }

        return false;
    }
};

// Helper function to create a binary tree
Node* createBinaryTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Solution solution;

    // Create two binary trees
    Node* tree1 = createBinaryTree();
    Node* tree2 = createBinaryTree();

    // Check if the two trees are isomorphic
    bool isIsomorphic = solution.isIsomorphic(tree1, tree2);

    if (isIsomorphic) {
        std::cout << "The trees are isomorphic." << std::endl;
    } else {
        std::cout << "The trees are not isomorphic." << std::endl;
    }

    // Remember to free the allocated memory to avoid memory leaks
    // Add code to delete the tree nodes here

    return 0;
}
