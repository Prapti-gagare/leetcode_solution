#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        priority_queue<pair<int, int>> pq;

        for (auto x : mp)
        {
            pq.push({x.second, x.first});
        }

        vector<int> ans;

        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    Solution obj;

    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top K Frequent Elements: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}