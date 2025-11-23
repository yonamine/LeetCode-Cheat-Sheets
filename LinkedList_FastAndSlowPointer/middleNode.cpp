#include <iostream>

struct ListNode {
    ListNode(int value) : value{value}, next{nullptr} {}
    int value{-1};
    ListNode *next{nullptr};
};

// Append a new node with the given value at the end of the list.
// Returns (possibly new) head pointer.
ListNode *appendNode(ListNode *head, int value) {
    ListNode *node = new ListNode(value);

    // Empty List: new node becomes the head
    if (head == nullptr) {
        return node;
    }

    // Non-empty list: walk to the last node
    ListNode *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = node;

    return head;
}

void printList(ListNode* head) {
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << " ";
    }
    std::cout << '\n';
}

ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while ((fast != nullptr) && (fast->next != nullptr)) {
        slow = slow->next;          // moves one step
        fast = fast->next->next;    // moves two step
    }

    return slow; // slow is not at the middle
}

int main() {
    ListNode *head{nullptr};
    head = appendNode(head, 0);
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4); // middle
    head = appendNode(head, 5);
    head = appendNode(head, 6);
    head = appendNode(head, 7);
    head = appendNode(head, 8);
    // head = appendNode(head, 9);


    ListNode *middle = middleNode(head);
    if (middle != nullptr) {
        std::cout << "Middle Value: " << middle->value << '\n';
    }
}
