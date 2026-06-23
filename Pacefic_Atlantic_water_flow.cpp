#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(heights, nr, nc, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific Ocean
        for (int i = 0; i < rows; i++)
            dfs(heights, i, 0, pacific);

        for (int j = 0; j < cols; j++)
            dfs(heights, 0, j, pacific);

        // Atlantic Ocean
        for (int i = 0; i < rows; i++)
            dfs(heights, i, cols - 1, atlantic);

        for (int j = 0; j < cols; j++)
            dfs(heights, rows - 1, j, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> heights(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heights[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> ans = obj.pacificAtlantic(heights);

    cout << "Cells from which water can flow to both oceans:\n";
    for (auto &cell : ans) {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }

    return 0;
}