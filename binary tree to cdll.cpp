#include <iostream>

// Definition for a binary tree node.
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* head;
    Node* tail;

    void inorder(Node* root) {
        if (!root)
            return;

        inorder(root->left);

        Node* curr = new Node(root->data);
        if (tail) {
            tail->right = curr;
            curr->left = tail;
        } else
            head = curr;
        tail = curr;

        inorder(root->right);
    }

    Node* bTreeToCList(Node* root) {
        tail = head = nullptr;

        inorder(root);

        if (head && tail) {
            head->left = tail;
            tail->right = head;
        }

        return head;
    }
};

// Utility function to print circular doubly linked list
void printList(Node* head) {
    if (!head)
        return;

    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->right;
    } while (temp != head);

    std::cout << std::endl;
}

int main() {
    // Example usage:
    // Construct a simple binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution solution;
    Node* circularList = solution.bTreeToCList(root);

    // Print the circular doubly linked list
    printList(circularList);

    // Clean up (free memory)
    // Note: This part is usually handled differently in a real-world scenario.
    // In this simple example, we're manually deleting each node.
    while (circularList) {
        Node* temp = circularList;
        circularList = circularList->right;
        delete temp;
    }

    return 0;
}
