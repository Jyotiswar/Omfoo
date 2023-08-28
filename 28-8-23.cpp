#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates from a linked list
Node* removeDuplicates(Node* head) {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        while (next && next->data == curr->data)
            next = next->next;
        curr->next = next;
        curr = curr->next;
    }
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);

    std::cout << "Original Linked List: ";
    printList(head);

    // Removing duplicates
    head = removeDuplicates(head);

    std::cout << "Linked List after Removing Duplicates: ";
    printList(head);

    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
