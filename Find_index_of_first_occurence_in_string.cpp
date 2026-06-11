#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz_h = haystack.size();
        int sz_n = needle.size();

        for (int i = 0; i <= sz_h - sz_n; i++) {
            string s1 = haystack.substr(i, sz_n);

            if (s1 == needle)
                return i;
        }

        return -1;
    }
};

int main() {
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    Solution obj;
    int result = obj.strStr(haystack, needle);

    cout << "Output: " << result << endl;

    return 0;
}