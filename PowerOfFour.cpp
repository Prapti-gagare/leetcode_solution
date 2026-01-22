#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        while (n % 4 == 0) {
            n = n / 4;
        }
        return (n == 1);
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPowerOfFour(n))
        cout << n << " is a power of 4" << endl;
    else
        cout << n << " is NOT a power of 4" << endl;

    return 0;
}
