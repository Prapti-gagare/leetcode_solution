#include <iostream>
#include <vector>
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

bool isPalindrome(ListNode* head)
{
    vector<int> arr;
    ListNode* curr = head;

    while(curr != NULL)
    {
        arr.push_back(curr->val);
        curr = curr->next;
    }

    int i = 0, j = arr.size() - 1;

    while(i < j)
    {
        if(arr[i] != arr[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if(isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}