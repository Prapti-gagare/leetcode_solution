#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 5, 6};

    cout << obj.searchInsert(nums, 5) << endl; 
    cout << obj.searchInsert(nums, 2) << endl; 
    cout << obj.searchInsert(nums, 7) << endl; 
    cout << obj.searchInsert(nums, 0) << endl; 

    return 0;
}