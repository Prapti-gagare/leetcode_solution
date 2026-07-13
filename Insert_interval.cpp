#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> temp;

        // Copy all intervals
        for (auto interval : intervals)
            temp.push_back(interval);

        // Add new interval
        temp.push_back(newInterval);

        // Sort according to start time
        sort(temp.begin(), temp.end());

        vector<vector<int>> ans;

        int start = temp[0][0];
        int end = temp[0][1];

        for (int i = 1; i < temp.size(); i++) {

            if (temp[i][0] <= end) {
                end = max(end, temp[i][1]);
            }
            else {
                ans.push_back({start, end});
                start = temp[i][0];
                end = temp[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};

int main() {

    // Input intervals
    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    // New interval
    vector<int> newInterval = {2, 5};

    Solution obj;

    vector<vector<int>> result = obj.insert(intervals, newInterval);

    cout << "Merged Intervals:\n";
    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}