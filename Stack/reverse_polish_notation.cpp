#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(const string &t : tokens)
        {
            if(t == "+" || t == "-" || t == "*" || t == "/")
            {
                int rtg = stk.top();
                stk.pop();

                int lft = stk.top();
                stk.pop();

                int result = 0;

                if(t == "+") result = lft + rtg;
                else if(t == "-") result = lft - rtg;
                else if(t == "*") result = lft * rtg;
                else if(t == "/") result = lft / rtg;

                stk.push(result);
            }
            else
            {
                stk.push(stoi(t));
            }
        }

        return stk.top();
    }
};

int main()
{
    int n;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<string> tokens(n);

    cout << "Enter tokens (numbers or operators):" << endl;
    for(int i = 0; i < n; i++)
        cin >> tokens[i];

    Solution obj;
    int result = obj.evalRPN(tokens);

    cout << "Result = " << result << endl;

    return 0;
}