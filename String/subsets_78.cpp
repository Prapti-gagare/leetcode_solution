#include <iostream>
#include <vector>
using namespace std;

void backtrack(int idx, vector<int>& nums,
               vector<int>& curr,
               vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(curr);
        return;
    }

    curr.push_back(nums[idx]);
    backtrack(idx + 1, nums, curr, ans);
    curr.pop_back();
    backtrack(idx + 1, nums, curr, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;

    backtrack(0, nums, curr, ans);

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (auto subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}