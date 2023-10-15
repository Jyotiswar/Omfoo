#include <iostream>
#include <vector>

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
    vector<int> arr;

    void inorder(Node* node) {
        if (!node)
            return;
        inorder(node->left);
        arr.push_back(node->data);
        inorder(node->right);
    }

    Node* createBST(int low, int high) {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;
        Node* root = new Node(arr[mid]);

        root->left = createBST(low, mid - 1);
        root->right = createBST(mid + 1, high);

        return root;
    }

    Node* buildBalancedTree(Node* root) {
        inorder(root);
        return createBST(0, arr.size() - 1);
    }
};

int main() {
    Solution solution;

    // Create a sample binary search tree
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    // Build a balanced binary search tree from the given tree
    Node* balancedRoot = solution.buildBalancedTree(root);

    cout << "Inorder traversal of the balanced tree: ";
    solution.inorder(balancedRoot);
    for (int value : solution.arr) {
        cout << value << " ";
    }
    cout << endl;

    // You should add memory cleanup to delete the dynamically allocated nodes here.

    return 0;
}
