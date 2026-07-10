#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if (n == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> ans = obj.merge(intervals);

    cout << "Merged Intervals:\n";

    for (auto &v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}