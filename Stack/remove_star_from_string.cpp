#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        for (auto ch : s) {
            if (ch != '*') {
                stk.push(ch);
            }
            else {
                if (!stk.empty()) {
                    stk.pop();
                }
            }
        }

        string ans;
        while (stk.size() > 0) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = obj.removeStars(s);

    cout << "Result: " << result << endl;

    return 0;
}