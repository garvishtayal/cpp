#include <iostream>
using namespace std;

/*
    Floyd's Cycle Detection (Tortoise & Hare)

    Phase 1: Detect cycle
    - slow moves 1 step
    - fast moves 2 steps
    - if they meet → cycle exists

    Phase 2: Find cycle start
    - reset slow to head
    - move both 1 step
    - meeting point = start of cycle

    Time: O(n), Space: O(1)
*/

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* detectCycleStart(Node* head) {
    Node *slow = head, *fast = head;

    // Phase 1: detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // No cycle
    if (!fast || !fast->next) return nullptr;

    // Phase 2: find start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5 -> (back to 3)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;

    Node* start = detectCycleStart(head);

    if (start)
        cout << "Cycle starts at: " << start->val << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
