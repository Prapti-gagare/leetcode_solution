#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        int index = -1;  
        
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }
        
        if (index == -1) return word;  

        for (int i = 0; i <= index; i++) {
            st.push(word[i]);
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }


        for (int i = index + 1; i < word.length(); i++) {
            result += word[i];
        }

        return result;
    }
};

int main() {
    string word;
    char ch;
    cout << "Enter the word: ";
    cin >> word;
    cout << "Enter the character: ";
    cin >> ch;

    Solution sol;
    string reversedWord = sol.reversePrefix(word, ch);

    cout << "Result: " << reversedWord << endl;

    return 0;
}