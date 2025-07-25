#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string a = "abcde", b = "ace";
    cout << "LCS length: " << longestCommonSubsequence(a, b) << endl;
    return 0;
}