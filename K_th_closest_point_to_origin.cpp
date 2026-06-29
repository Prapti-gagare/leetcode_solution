#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;
        for(int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            minHeap.push({dist, i});
        }

        vector<vector<int>> ans;

        while(k--) {

            int index = minHeap.top().second;
            ans.push_back(points[index]);
            minHeap.pop();
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> points = {
        {1,3},
        {-2,2}
    };

    int k = 1;

    vector<vector<int>> ans = obj.kClosest(points, k);

    cout << "Closest Points:\n";

    for(auto point : ans) {
        cout << "[" << point[0] << "," << point[1] << "]\n";
    }

    return 0;
}