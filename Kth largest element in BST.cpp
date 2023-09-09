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
    void modifiedInorder(Node* root, int& k, int& ans) {
        if (!root)
            return;

        modifiedInorder(root->right, k, ans);
        --k;
        if (!k) ans = root->data;
        modifiedInorder(root->left, k, ans);
    }

    int kthLargest(Node* root, int k) {
        int ans = -1; // Initialize ans with a default value
        modifiedInorder(root, k, ans);
        return ans;
    }
};

int main() {
    // Create a sample binary search tree
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    
    Solution solution;

    // Find the 3rd largest element in the BST
    int k = 3;
    int result = solution.kthLargest(root, k);
    
    std::cout << "The " << k << "rd largest element is: " << result << std::endl;

    // Clean up memory (you should have a proper memory deallocation function)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
