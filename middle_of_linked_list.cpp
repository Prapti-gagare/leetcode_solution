#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;

        while (f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
};

ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* head = nullptr;

    // Example: 1 -> 2 -> 3 -> 4 -> 5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    printList(head);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    cout << "Middle Node Value: " << mid->val << endl;

    return 0;
}