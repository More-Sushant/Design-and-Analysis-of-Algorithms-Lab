#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    // Create a 2D DP array
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // Sum 0 can be achieved by excluding all elements
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // Exclude the current element
            dp[i][j] = dp[i-1][j];
            // Include the current element (if it does not exceed the current sum)
            if (j >= set[i-1]) {
                dp[i][j] = dp[i][j] || dp[i-1][j-set[i-1]];
            }
        }
    }

    // The result is whether we can achieve the target sum using all elements
    return dp[n][sum];
}

int main() {
    // Test cases
    vector<int> set1 = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    cout << "Is there a subset with sum " << sum1 << "? " << (isSubsetSum(set1, sum1) ? "True" : "False") << endl;

    vector<int> set2 = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    cout << "Is there a subset with sum " << sum2 << "? " << (isSubsetSum(set2, sum2) ? "True" : "False") << endl;

    return 0;
}
