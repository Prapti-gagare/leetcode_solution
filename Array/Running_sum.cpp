#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main() {
    Solution obj;
    vector<int> nums;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    vector<int> result = obj.runningSum(nums);

    cout << "Running Sum: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
