#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) 
    {
        if (x < 0)
            return 0;

        double ans = sqrt(x);
        return (int)ans;
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.mySqrt(x);
    return 0;
}
