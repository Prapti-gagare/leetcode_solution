#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        int sz1 = s.size();
        int sz2 = t.size();
        int i = 0, j = 0;

        if (sz2 < sz1)
            return false;

        while (i < sz1 && j < sz2) {
            if (s[i] == t[j]) {
                i++;
                j++;
                cnt++;
            } else {
                j++;
            }
        }

        return (sz1 == cnt);
    }
};

int main() {
    Solution obj;
    string s, t;

    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    if (obj.isSubsequence(s, t))
        cout << "\"" << s << "\" is a subsequence of \"" << t << "\"" << endl;
    else
        cout << "\"" << s << "\" is NOT a subsequence of \"" << t << "\"" << endl;

    return 0;
}
