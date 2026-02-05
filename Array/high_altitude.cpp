#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxA = 0, currA = 0;

        for (int i = 0; i < n; i++) {
            currA = currA + gain[i];
            maxA = max(currA, maxA);
        }
        return maxA;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> gain(n);
    cout << "Enter the gain values: ";
    for (int i = 0; i < n; i++) {
        cin >> gain[i];
    }

    int result = obj.largestAltitude(gain);
    cout << "Largest Altitude = " << result << endl;

    return 0;
}
