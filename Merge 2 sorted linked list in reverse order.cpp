#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* reverseList(Node* curr) {
        if (!curr || !(curr->next))
            return curr;
        auto res = reverseList(curr->next);
        curr->next->next = curr;
        curr->next = nullptr;
        return res;
    }

    Node* mergeResult(Node* node1, Node* node2) {
        if (!node1)
            return reverseList(node2);
        if (!node2)
            return reverseList(node1);

        Node* curr = new Node(0);  // Dummy node
        Node* head = curr;

        while (node1 && node2) {
            if (node1->data < node2->data) {
                curr->next = node1;
                node1 = node1->next;
            } else {
                curr->next = node2;
                node2 = node2->next;
            }
            curr = curr->next;
        }

        while (node1) {
            curr->next = node1;
            node1 = node1->next;
            curr = curr->next;
        }

        while (node2) {
            curr->next = node2;
            node2 = node2->next;
            curr = curr->next;
        }

        head = head->next;
        return reverseList(head);
    }
};

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    Solution solution;
    Node* mergedResult = solution.mergeResult(list1, list2);

    std::cout << "Merged and reversed result: ";
    printList(mergedResult);

    return 0;
}
