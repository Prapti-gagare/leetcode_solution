#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skips = 0, skipT = 0;

        while(i >= 0 || j >= 0)
        {
            while(i >= 0)
            {
                if(s[i] == '#')
                {
                    skips++;
                    i--;
                }
                else if(skips > 0)
                {
                    skips--;
                    i--;
                }
                else
                    break;
            }

            while(j >= 0)
            {
                if(t[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if(skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                    break;
            }

            if(i >= 0 && j >= 0 && s[i] != t[j])
                return false;

            if((i >= 0) != (j >= 0))
                return false;

            i--;
            j--;
        }

        return true;
    }
};

int main()
{
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    Solution obj;

    if(obj.backspaceCompare(s, t))
        cout << "Strings are equal after processing backspaces" << endl;
    else
        cout << "Strings are NOT equal after processing backspaces" << endl;

    return 0;
}