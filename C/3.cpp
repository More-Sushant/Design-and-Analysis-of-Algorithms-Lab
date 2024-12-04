#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

bool canTransform(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();

    // DP table: dp[i][j] indicates if s1[0..i-1] can transform to s2[0..j-1]
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Base cases
    dp[0][0] = true; // Two empty strings match

    // If s2 is empty, only lowercase characters in s1 can be ignored
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] && islower(s1[i-1]);
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (toupper(s1[i-1]) == s2[j-1]) {
                // If characters match (case-insensitive), two options:
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
            } else if (islower(s1[i-1])) {
                // Skip lowercase characters if they don't match
                dp[i][j] = dp[i-1][j];
            } else {
                // Uppercase characters must match
                dp[i][j] = false;
            }
        }
    }

    // The answer is whether s1 can transform to s2
    return dp[n][m];
}

int main() {
    // Test cases
    string s1 = "daBcd", s2 = "ABC";
    cout << "Can transform \"" << s1 << "\" to \"" << s2 << "\": " << (canTransform(s1, s2) ? "yes" : "no") << endl;

    s1 = "argaju";
    s2 = "RAJ";
    cout << "Can transform \"" << s1 << "\" to \"" << s2 << "\": " << (canTransform(s1, s2) ? "yes" : "no") << endl;

    return 0;
}
