#include <iostream>

// Define the Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* insert(Node* node, int data) {
        if (!node)
            return new Node(data);

        if (data > node->data) {
            if (!node->right)
                node->right = new Node(data);
            else
                insert(node->right, data);
        } else if (data < node->data) {
            if (!node->left)
                node->left = new Node(data);
            else
                insert(node->left, data);
        }

        return node;
    }
};

// Function to print the binary search tree in inorder traversal
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Solution solution;
    Node* root = nullptr; // Initialize an empty binary search tree

    // Insert elements into the BST
    root = solution.insert(root, 50);
    solution.insert(root, 30);
    solution.insert(root, 20);
    solution.insert(root, 40);
    solution.insert(root, 70);
    solution.insert(root, 60);
    solution.insert(root, 80);

    // Print the BST in inorder traversal
    std::cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (you should have a proper memory deallocation function)
    // You can implement a separate function to delete the entire tree.

    return 0;
}
