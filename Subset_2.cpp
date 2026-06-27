#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int start, vector<int>& nums) {
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);

            backtrack(i + 1, nums);

            // Backtrack
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        backtrack(0, nums);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "All Unique Subsets:\n";

    for (auto subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}