#include <iostream>
#include <vector>

struct ListNode {
    ListNode(int value) : value{value}, next{nullptr} {}
    int value{-1};
    ListNode *next{nullptr};
};

// Floyd's Cycle Detection
// Detect if the linked list has a cycle
bool hasCycle(ListNode *head) {
    if (head == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while ((fast != nullptr) && (fast->next != nullptr)) {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
        if (slow == fast) {      // meeting point
            return true;         // cycle detected
        }
    }

    return false; // fast hit null => no cycle
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // create a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    bool cycle = hasCycle(head);
    std::cout << "Has cycle? " << (cycle ? "yes" : "no") << '\n';
}
