#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1)
                q.push({i, j});
        }
    }

    if (q.empty() || q.size() == n * n)
        return -1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int distance = -1;

    while (!q.empty()) {
        int sz = q.size();
        distance++;

        while (sz--) {
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> grid = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };

    cout << maxDistance(grid);

    return 0;
}