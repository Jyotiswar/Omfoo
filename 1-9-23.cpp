#include <iostream>
#include <queue>

using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to print the corner nodes of a binary tree
void printCorner(Node *root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        Node* first = q.front();
        Node* last;

        while (sz--) {
            last = q.front();
            q.pop();
            if (last->left)
                q.push(last->left);
            if (last->right)
                q.push(last->right);
        }

        if (first != last)
            cout << first->data << " " << last->data << " ";
        else
            cout << first->data << " ";
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Corner nodes of the binary tree are: ";
    printCorner(root);
    cout << endl;

    return 0;
}
