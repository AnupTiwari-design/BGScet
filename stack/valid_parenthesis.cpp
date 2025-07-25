#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // If it's an opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        // If it's a closing bracket, check for match
        else {
            if (st.empty()) return false;  // No matching opening
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty(); // Valid if all opened are closed
}

int main() {
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (isValid(input)) {
        cout << "Valid parentheses\n";
    } else {
        cout << "Invalid parentheses\n";
    }

    return 0;
}