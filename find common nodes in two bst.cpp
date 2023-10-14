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
    vector<int> out;

    bool find(Node* node, int x) {
        if (!node)
            return false;

        if (node->data == x)
            return true;
        if (node->data > x)
            return find(node->left, x);

        return find(node->right, x);
    }

    void inorder(Node* root1, Node* root2) {
        if (!root1)
            return;

        inorder(root1->left, root2);
        if (find(root2, root1->data))
            out.push_back(root1->data);
        inorder(root1->right, root2);
    }

    vector<int> findCommon(Node* root1, Node* root2) {
        inorder(root1, root2);
        return out;
    }
};

int main() {
    // Create two sample binary trees
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);
    root1->left->left = new Node(3);
    root1->left->right = new Node(7);

    Node* root2 = new Node(15);
    root2->left = new Node(7);
    root2->right = new Node(30);
    root2->left->left = new Node(2);
    root2->left->right = new Node(10);

    Solution solution;

    vector<int> commonElements = solution.findCommon(root1, root2);

    cout << "Common elements between the two trees: ";
    for (int element : commonElements) {
        cout << element << " ";
    }
    cout << endl;

    // You should add memory cleanup to delete the dynamically allocated nodes here.

    return 0;
}
