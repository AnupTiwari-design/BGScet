#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) return 1;

    vector<int> dp(n + 1);
    dp[0] = 1; // 1 way to stay at ground
    dp[1] = 1; // 1 way to reach first step

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Total distinct ways to climb " << n << " steps: " << climbStairs(n) << endl;

    return 0;
}