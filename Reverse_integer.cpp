#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int MAX = INT_MAX / 10;
        int MIN = INT_MIN / 10;

        while (x != 0) {

            if (ans > MAX || ans < MIN)
                return 0;

            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int x;

    cout << "Enter an integer: ";
    cin >> x;

    int result = obj.reverse(x);

    cout << "Reversed number = " << result << endl;

    return 0;
}
