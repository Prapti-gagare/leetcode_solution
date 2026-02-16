#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            um[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &e : um) {
            ans.push_back(e.second);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;
    vector<vector<string>> result = obj.groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";
    for (auto group : result) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}
