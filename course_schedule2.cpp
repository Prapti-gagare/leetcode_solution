#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> indegree(numCourses, 0);

        for (auto x : adj)
        {
            for (int node : x)
            {
                indegree[node]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty())
        {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for (int next : adj[course])
            {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        if (ans.size() == numCourses)
            return ans;

        return {};
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    Solution sol;
    vector<int> order = sol.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course order exists." << endl;
    } else {
        cout << "Valid course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}