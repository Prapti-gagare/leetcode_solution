#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();   
        int m = matrix.size();      
        vector<int> cols(n, 0);
        vector<int> rows(m, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    cols[j] = 1;
                    rows[i] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(cols[j] == 1 || rows[i] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    for(auto &row : matrix) {
        for(int x : row)
            cout << x << " ";
        cout << endl;
    }

    obj.setZeroes(matrix);

    cout << "\nMatrix after setZeroes:\n";
    for(auto &row : matrix) {
        for(int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
