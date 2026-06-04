#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }

        int product = 1;

        while (n > 4) 
        {
            product *= 3;
            n -= 3;
        }

        return product * n;
    }
};

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << "Maximum Product = " << obj.integerBreak(n) << endl;

    return 0;
}