#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = '1';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r1, c1] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r1 + dr[k];
                int nc = c1 + dc[k];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    board[nr][nc] == 'O') {

                    board[nr][nc] = '1';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O')
                bfs(board, 0, c);

            if (board[rows - 1][c] == 'O')
                bfs(board, rows - 1, c);
        }

        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O')
                bfs(board, r, 0);

            if (board[r][cols - 1] == 'O')
                bfs(board, r, cols - 1);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == '1')
                    board[r][c] = 'O';
            }
        }
    }
};

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));

    cout << "Enter the board (O and X):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solve(board);

    cout << "\nOutput Board:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}