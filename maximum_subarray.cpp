#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int globalSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            currentSum += nums[i];

            globalSum = max(globalSum, currentSum);

            if (currentSum < 0)
                currentSum = 0;
        }

        return globalSum;
    }
};

int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution obj;
    cout << "Maximum Subarray Sum = " << obj.maxSubArray(nums);

    return 0;
}