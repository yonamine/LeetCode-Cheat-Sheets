#include <iostream>

struct ListNode {
    ListNode(int value) : value{value}, next{nullptr} {}
    int value;
    ListNode *next{nullptr};
};

// Reverse the list from position left to right (1-based indices)
// Returns the (possibly new) head
ListNode *reverseBetween(ListNode *head, int left, int right) {
    if ((head == nullptr) || (left == right)) {
        return head;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *previous = &dummy;

    // step 1: move previous to node before 'left'
    for (int i = 1; i < left; i++) {
        previous = previous->next;
    }

    // Now:
    // previous -> nodeBeforeLeft
    // current -> leftNode
    ListNode *current = previous->next;
    ListNode *next = nullptr;

    // step 2: reverse [left..right]
    // We'll do standard iterative reverse, but limited by ((right - left) + 1)
    // nodes
    ListNode *sub_previous = nullptr;
    ListNode *sub_current = current;
    for (int i = 0; i <= (right - left); i++) {
        next = sub_current->next;
        sub_current->next = sub_previous;
        sub_previous = sub_current;
        sub_current = next;
    }

    // After that:
    // sub_previous is the new head of reversed part
    // sub_current is the first node after the reversed part

    // step 3: reconnect
    previous->next = sub_previous;  // connect nodeBeforeLeft -> new head of reversed part
    current->next = sub_current;    // connect tail of reversed part -> rest of list

    return dummy.next;
}

void printList(ListNode* head) {
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << ' ';
    }
    std::cout << '\n';
}

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original: ";
    printList(head);
    // Original: 1 2 3 4 5

    head = reverseBetween(head, 2, 4);

    std::cout << "After reverseBetween(2, 4): ";
    printList(head);
    // After reverseBetween(2, 4): 1 4 3 2 5
}