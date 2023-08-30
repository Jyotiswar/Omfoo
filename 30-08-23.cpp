#include <iostream>

struct Node {
    int data;
    Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};

Node* deleteNode(Node *head, int x) {
    Node *toDelete;

    if (x == 1) {
        toDelete = head;
        head = head->next;
    } else {
        Node* itr = head;
        --x;
        while (--x) 
            itr = itr->next;

        toDelete = itr->next;
        itr->next = itr->next->next;
    }

    free(toDelete);
    return head;
}

void printList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printList(head);

    int positionToDelete = 3; // Change this to the desired position
    head = deleteNode(head, positionToDelete);

    std::cout << "Linked List after deleting position " << positionToDelete << ": ";
    printList(head);

    // Free memory
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
