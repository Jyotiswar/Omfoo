#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    void rearrange(Node *odd) {
        Node* even = odd;
        Node* revOdd = nullptr;
        Node* itr = odd;

        while (itr) {
            Node* nextItr = itr->next;
            if (nextItr) {
                even->next = itr->next->next;
                if (even->next)
                    even = even->next;
                nextItr->next = revOdd;
                revOdd = nextItr;
            } else
                break;
            itr = even;
        }
        even->next = revOdd;
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
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution solution;

    std::cout << "Original Linked List: ";
    printList(head);

    solution.rearrange(head);

    std::cout << "Rearranged Linked List: ";
    printList(head);

    // Free memory (you should free memory properly in a real program)
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
