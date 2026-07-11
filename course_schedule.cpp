#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {

        if (visited[node] == 1)
            return true;        

        if (visited[node] == 2)
            return false;       

        visited[node] = 1;

        for (int next : adj[node]) {
            if (dfs(next, adj, visited))
                return true;
        }

        visited[node] = 2;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, adj, visited))
                return false;
        }

        return true;
    }
};

int main() {

    Solution obj;

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1,0}
    };

    if (obj.canFinish(numCourses, prerequisites))
        cout << "true";
    else
        cout << "false";

    return 0;
}