#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            temp = curr->next;   // store next node
            curr->next = prev;   // reverse link
            prev = curr;         // move prev forward
            curr = temp;         // move curr forward
        }

        return prev; // new head
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}