#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPowerOfThree(n))
        cout << n << " is a power of 3" << endl;
    else
        cout << n << " is NOT a power of 3" << endl;

    return 0;
}
