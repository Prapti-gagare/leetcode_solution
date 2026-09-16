#include <iostream>
#include <stack>
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
    ListNode* removeNodes(ListNode* head)
    {
        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr != NULL)
        {
            while (!st.empty() && st.top()->val < curr->val)
            {
                st.pop();
            }

            st.push(curr);
            curr = curr->next;
        }

        ListNode* newHead = NULL;

        while (!st.empty())
        {
            ListNode* node = st.top();
            st.pop();

            node->next = newHead;
            newHead = node;
        }

        return newHead;
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
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    Solution obj;
    head = obj.removeNodes(head);

    printList(head);

    return 0;
}