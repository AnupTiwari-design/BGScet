#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;

    // Optional: print full series
    cout << "\nFibonacci Series: ";
    for (int i = 0; i <= n; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}