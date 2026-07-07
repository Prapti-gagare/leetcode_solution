#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int houseRob(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;

        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;

            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int first = houseRob(nums, 0, n - 2);
        int second = houseRob(nums, 1, n - 1);

        return max(first, second);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 2};

    cout << obj.rob(nums);

    return 0;
}