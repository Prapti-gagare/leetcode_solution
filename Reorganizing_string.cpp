#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {

        int freq[26] = {0};

        for (char ch : s)
            freq[ch - 'a']++;

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], char(i + 'a')});
        }

        string ans = "";

        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {

            auto [fr, ch] = pq.top();
            pq.pop();

            ans += ch;
            fr--;

            if (prev.first > 0)
                pq.push(prev);

            prev = {fr, ch};
        }

        if (ans.length() != s.length())
            return "";

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    string result = obj.reorganizeString(s);

    if (result == "")
        cout << "Reorganization is not possible." << endl;
    else
        cout << "Reorganized string: " << result << endl;

    return 0;
}