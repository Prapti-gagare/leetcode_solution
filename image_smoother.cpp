#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        int LR = rows - 1;
        int LC = cols - 1;

        for (int rI = 0; rI < rows; rI++) {
            for (int cI = 0; cI < cols; cI++) {
                int sum = 0;
                int cnt = 0;

                int SR = (rI == 0) ? 0 : (rI - 1);
                int eR = (rI == LR) ? rI : (rI + 1);
                int SC = (cI == 0) ? 0 : (cI - 1);
                int eC = (cI == LC) ? cI : (cI + 1);

                for (int i = SR; i <= eR; i++) {
                    for (int j = SC; j <= eC; j++) {
                        sum += img[i][j];
                        cnt++;
                    }
                }

                ans[rI][cI] = sum / cnt;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    vector<vector<int>> img(r, vector<int>(c));
    cout << "Enter image matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> img[i][j];
        }
    }

    vector<vector<int>> result = obj.imageSmoother(img);

    cout << "Smoothed image:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
