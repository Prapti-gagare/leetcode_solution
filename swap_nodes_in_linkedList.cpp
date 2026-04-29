#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* first = head;
        int count = k;

        while (count > 1)
        {
            first = first->next;
            count--;
        }

        ListNode* temp = first;
        ListNode* second = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;
    head = obj.swapNodes(head, k);

    printList(head);

    return 0;
}