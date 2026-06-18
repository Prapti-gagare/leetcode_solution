#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Push all 0's into the queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Directions: Up, Down, Left, Right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                !visited[nr][nc]) {

                mat[nr][nc] = mat[r][c] + 1;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return mat;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter the matrix (0s and 1s):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans = updateMatrix(mat);

    cout << "\nDistance Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}