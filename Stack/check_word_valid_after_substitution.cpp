#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stk;

        for (auto e : s)
        {
            if (e != 'c')
            {
                stk.push(e);
            }
            else
            {
                if (stk.size() < 2 || stk.top() != 'b')
                    return false;

                stk.pop();  // remove 'b'

                if (stk.top() != 'a')
                    return false;

                stk.pop();  // remove 'a'
            }
        }

        return stk.empty();
    }
};

int main()
{
    Solution obj;
    string s;

    cout << "Enter string: ";
    cin >> s;

    if (obj.isValid(s))
        cout << "Valid string" << endl;
    else
        cout << "Invalid string" << endl;

    return 0;
}