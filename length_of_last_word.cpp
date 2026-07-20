#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int count = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Length of last word: " << obj.lengthOfLastWord(s) << endl;

    return 0;
}