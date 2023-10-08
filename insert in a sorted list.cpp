#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);
        if (!head || head->data >= data) {
            newNode->next = head;
            return newNode;
        }

        Node* itr = head;
        while (itr->next && itr->next->data < data) {
            itr = itr->next;
        }

        newNode->next = itr->next;
        itr->next = newNode;
        return head;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);

    Solution solution;

    std::cout << "Original Linked List: ";
    printList(head);

    int newData = 4;
    head = solution.sortedInsert(head, newData);

    std::cout << "Linked List after inserting " << newData << ": ";
    printList(head);

    // Free memory (you should free memory properly in a real program)
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
