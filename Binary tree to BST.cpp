#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(Node* root, vector<Node*>& nodes) {
        if (!root)
            return;

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    Node* binaryTreeToBST(Node* root) {
        vector<Node*> nodes;
        inorder(root, nodes);
        vector<int> values;
        for (auto node : nodes)
            values.push_back(node->data);

        sort(values.begin(), values.end());

        for (int i = 0; i < nodes.size(); ++i)
            nodes[i]->data = values[i];

        return root;
    }
};

// Helper function to print the inorder traversal of a BST
void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Solution solution;

    // Create a sample binary tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // Convert the binary tree to a BST
    Node* result = solution.binaryTreeToBST(root);

    // Print the inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";
    printInorder(result);
    cout << endl;

    return 0;
}
