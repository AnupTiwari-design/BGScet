#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;  // stack stores indices

    for (int i = 0; i < n; ++i) {
     while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            result[prev] = i - prev;
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temps);

    cout << "Output: ";
    for (int days : res) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}