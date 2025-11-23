#include <iostream>

struct ListNode {
    ListNode(int value) : value{value}, next{nullptr} {}
    int value{-1};
    ListNode *next{nullptr};
};

// Reverse the entire linked list iteratively
// Returns the new head
ListNode *reverseList(ListNode *head) {
    ListNode *previous = nullptr;
    ListNode *current = head;

    while (current != nullptr) {
        ListNode *next = current->next; // save next node
        current->next = previous;       // reverse pointer
        previous = current;             // move previous forward
        current  = next;                // move current forward
    }

    return previous; // new head
}

// Recursive version: reverse the entire list.
ListNode *reverseList_recursive(ListNode *head) {
    // base case: empty list or single node
    if ((head == nullptr) || (head->next == nullptr)) {
        return head;
    }

    // Reverse the rest of the list
    ListNode* new_head = reverseList_recursive(head->next);

    // Put head at the end
    head->next->next = head;
    head->next = nullptr;

    return new_head;
}

void printList(ListNode* head) {
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << ' ';
    }
    std::cout << '\n';
}

int main() {
    // Build: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original: ";
    printList(head);
    // Original: 1 2 3 4 5

    // head = reverseList(head);
    head = reverseList_recursive(head);

    std::cout << "Reversed: ";
    printList(head);
    // Reversed: 5 4 3 2 1
}
