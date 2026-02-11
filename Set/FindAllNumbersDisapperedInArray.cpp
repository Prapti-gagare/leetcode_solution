#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
