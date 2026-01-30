#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz);

        for (int i = 0; i < sz; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    vector<int> result = s.buildArray(nums);

    cout << "Result array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
