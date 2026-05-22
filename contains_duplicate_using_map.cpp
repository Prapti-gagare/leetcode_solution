#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        map<int, int> mp;

        for(int num : nums) {

            mp[num]++;

            // If frequency becomes more than 1
            if(mp[num] > 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 1};

    Solution obj;

    if(obj.containsDuplicate(nums))
        cout << "Contains Duplicate";
    else
        cout << "No Duplicate";

    return 0;
}