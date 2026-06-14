#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& grid, int r, int c) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    q.push({r, c});
    grid[r][c] = 0;

    int area = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int k = 0; k < 4; k++) {
            int nr = x + dr[k];
            int nc = y + dc[k];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                grid[nr][nc] == 1) {

                q.push({nr, nc});
                grid[nr][nc] = 0;
                area++;
            }
        }
    }

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int maxArea = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                maxArea = max(maxArea, bfs(grid, r, c));
            }
        }
    }

    return maxArea;
}

int main()
 {
    vector<vector<int>> grid = {
        {0,0,1,0,0},
        {1,1,1,0,1},
        {0,1,0,0,1},
        {0,0,0,1,1}
    };

    cout << "Maximum Area of Island: "
         << maxAreaOfIsland(grid) << endl;

    return 0;
}