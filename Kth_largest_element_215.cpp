#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int sz = nums.size();

        if (sz < k)
            return 0;

        priority_queue<int> heap(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < k; i++)
        {
            ans = heap.top();
            heap.pop();
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << obj.findKthLargest(nums, k);

    return 0;
}