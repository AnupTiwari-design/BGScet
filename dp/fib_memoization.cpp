#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> dp(n + 1, -1); // initialize all values to -1

    cout << "Fibonacci(" << n << ") = " << fib(n, dp) << endl;

    cout << "\nFibonacci Series: ";
    for (int i = 0; i <= n; i++) {
        cout << fib(i, dp) << " ";
    }
    cout << endl;

    return 0;
}