#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> s;

        for(int num : nums) {

            // If already exists
            if(s.find(num) != s.end()) {
                return true;
            }

            s.insert(num);
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