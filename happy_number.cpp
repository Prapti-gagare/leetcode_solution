#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (n != 1 && seen.count(n) == 0)
        {
            seen.insert(n);

            int sum = 0;

            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return n == 1;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isHappy(n))
        cout << n << " is a Happy Number." << endl;
    else
        cout << n << " is NOT a Happy Number." << endl;

    return 0;
}