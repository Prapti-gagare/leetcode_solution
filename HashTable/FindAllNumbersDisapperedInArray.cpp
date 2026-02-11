#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> um;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            um[nums[i]] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (um.find(i) == um.end())
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    vector<int> result = obj.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}
