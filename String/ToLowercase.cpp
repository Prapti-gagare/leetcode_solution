#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string toLowerCase(string s)
     {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z')
                c = c + 32;
        }
        return s;
    }
};

int main() 
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    Solution obj;
    cout << "Lowercase string: " << obj.toLowerCase(s);

    return 0;
}
