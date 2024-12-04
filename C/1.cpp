#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeSum(int sum, const vector<int>& coins) {
    // dp[i] will be storing the number of ways to make sum i
    vector<int> dp(sum + 1, 0);
    
    // There is one way to make sum 0 (by using no coins)
    dp[0] = 1;
    
    // Loop through each coin
    for (int coin : coins) {
        // Update dp table for each sum that is >= coin value
        for (int i = coin; i <= sum; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    // dp[sum] will hold the answer (number of ways to make the given sum)
    return dp[sum];
}

int main() {
    // Test cases
    int sum = 4;
    vector<int> coins = {1, 2, 3};
    cout << "Number of ways to make sum " << sum << " with coins {1, 2, 3}: " << countWaysToMakeSum(sum, coins) << endl;
    
    sum = 10;
    coins = {2, 5, 3, 6};
    cout << "Number of ways to make sum " << sum << " with coins {2, 5, 3, 6}: " << countWaysToMakeSum(sum, coins) << endl;

    return 0;
}
// The time complexity is O(N×S), where N is the number of coins and S is the target sum, because we iterate through each coin and update the DP table for each sum.
