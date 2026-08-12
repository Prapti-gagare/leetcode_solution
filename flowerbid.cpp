#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int sz = fb.size();
        int cnt = 0;

        for (int i = 0; i < sz; ++i) {
            if (fb[i] == 0) {
                bool lft = false;
                if (i == 0 || fb[i - 1] == 0)
                    lft = true;

                bool rgt = false;
                if (i == sz - 1 || fb[i + 1] == 0)
                    rgt = true;

                if (lft == true && rgt == true) {
                    fb[i] = 1;
                    cnt++;
                }
            }
        }
        return (cnt >= n);
    }
};

int main() {
    Solution s;
    int size, n;

    cout << "Enter size of flowerbed: ";
    cin >> size;

    vector<int> fb(size);
    cout << "Enter flowerbed elements (0 or 1): ";
    for (int i = 0; i < size; i++) {
        cin >> fb[i];
    }

    cout << "Enter number of flowers to place: ";
    cin >> n;

    if (s.canPlaceFlowers(fb, n))
        cout << "Yes, flowers can be placed." << endl;
    else
        cout << "No, flowers cannot be placed." << endl;

    return 0;
}
