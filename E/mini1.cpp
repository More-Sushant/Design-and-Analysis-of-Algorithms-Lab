#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimized function to calculate the maximum amount of money that can be robbed
int houseRobberOptimized(vector<int>& money) {
    int prev1 = 0, prev2 = 0;
    
    for (int m : money) {
        int curr = max(prev1, m + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// Main function to test the implementation
int main() {
    vector<int> money = {1, 2, 3, 1, 10, 50};
    cout << "Maximum money that can be robbed: " << houseRobberOptimized(money) << endl;
    return 0;
}
