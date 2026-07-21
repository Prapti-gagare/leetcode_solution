#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }
        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0) {
                return false;
            }
            freq[ch - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    if (obj.canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}