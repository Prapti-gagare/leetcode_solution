#include <iostream>
#include <string>
using namespace std;

int repeatedStringMatch(string a, string b) {
    string s = "";
    int count = 0;
    while (s.length() < b.length()) {
        s += a;
        count++;
    }
    if (s.find(b) != string::npos)
        return count;
    s += a;
    count++;

    if (s.find(b) != string::npos)
        return count;

    return -1;
}

int main() {
    string a, b;

    cout << "Enter string a: ";
    cin >> a;

    cout << "Enter string b: ";
    cin >> b;

    int ans = repeatedStringMatch(a, b);

    cout << "Output: " << ans << endl;

    return 0;
}