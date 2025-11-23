#include <iostream>
#include <vector>

struct ListNode {
    ListNode(int value) : value{value}, next{nullptr} {}
    int value{-1};
    ListNode *next{nullptr};
};

// Floyd's Cycle Detection
// Find the node where the cycle begins, or nullptr if there is no cycle
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // 1st step: detect if there is a cycle
    bool has_cycle = false;
    while((fast != nullptr) && (fast->next != nullptr)) {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
        if (slow == fast) {
            has_cycle = true;
            break;
        }
    }

    if (has_cycle == false) {
        return nullptr;
    }

    // 2nd step: find cycle entry
    ListNode *ptr1 = head;
    ListNode *ptr2 = slow; // meeting point
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1; // or ptr2, both are at cycle start
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

    ListNode *entry = detectCycle(head);
    if (entry) {
        std::cout << "Cycle entry value: " << entry->value << '\n';
    } else {
        std::cout << "No cycle\n";
    }
}
