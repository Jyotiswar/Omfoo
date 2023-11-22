#include <iostream>
#include <queue>
#include <utility>

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
    bool isSame(Node* r1, Node* r2) {
        if ((r1 == nullptr) ^ (r2 == nullptr))
            return false;

        return (r1 == nullptr) or (r1->data == r2->data);
    }

    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(Node* root) {
        if (!root)
            return true;

        queue<pair<Node*, Node*>> q;
        q.push({root->left, root->right});

        bool ok = true;

        while (ok and !q.empty()) {
            Node* left, *right;
            tie(left, right) = q.front();
            q.pop();

            ok = ok and isSame(left, right);

            if (ok and left) {
                q.push({left->left, right->right});
                q.push({left->right, right->left});
            }
        }

        return ok;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create a symmetric tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    // Check if the tree is symmetric
    if (solution.isSymmetric(root)) {
        cout << "The tree is symmetric.\n";
    } else {
        cout << "The tree is not symmetric.\n";
    }

    // Clean up memory (assuming you're not using smart pointers or a memory management library)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
