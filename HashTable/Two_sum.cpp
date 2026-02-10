#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> um;
        vector<int> ans;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int tmp = t - nums[i];
            if (um.find(tmp) != um.end()) {
                ans.push_back(i);
                ans.push_back(um[tmp]);
                return ans;
            }
            um[nums[i]] = i;
        }
        return ans;
    }
};

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    cout << "Indices: ";
    for (int i : result)
        cout << i << " ";

    return 0;
}
