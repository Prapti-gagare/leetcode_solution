#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            answer = max(answer, maxProd);
        }

        return answer;
    }
};

int main() {

    vector<int> nums = {2, 3, -2, 4};

    Solution obj;

    cout << "Maximum Product = " << obj.maxProduct(nums);

    return 0;
}