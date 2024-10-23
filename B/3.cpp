#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Helper function to compute the sum of tasks from index i to j
int sumTasks(const vector<int>& task, int i, int j) 
{
    int sum = 0;
    for (int k = i; k <= j; ++k) 
    {
        sum += task[k];
    }
    return sum;
}

int minWorkload(vector<int>& task, int D) 
{
    int N = task.size();
    
    // If the number of tasks is less than or equal to the number of days, return the maximum task.
    if (N <= D) 
    {
        return *max_element(task.begin(), task.end());
    }
    
    // Create a dp table to store minimum workload for i tasks in d days
    vector<vector<int>> dp(N + 1, vector<int>(D + 1, INT_MAX));
    
    // Base case: if there's only one day, the minimum workload is the sum of all tasks.
    dp[0][0] = 0; // 0 tasks in 0 days requires 0 workload

    for (int i = 1; i <= N; i++) 
    {
        dp[i][1] = sumTasks(task, 0, i - 1); // All tasks in one day
    }
    
    // Fill dp table
    for (int d = 2; d <= D; ++d) 
    {
        for (int i = d; i <= N; ++i) 
        { // We need at least 'd' tasks for 'd' days
            int current_work = 0;
            for (int j = i - 1; j >= d - 1; --j) 
            { // Check splitting points
                current_work += task[j];
                dp[i][d] = min(dp[i][d], max(dp[j][d - 1], current_work));
            }
        }
    }

    return dp[N][D];
}

int main() 
{
    vector<int> task1 = {3, 4, 7, 15};
    int D1 = 10;
    cout << "Minimum workload for task1: " << minWorkload(task1, D1) << endl; // Output: 4

    vector<int> task2 = {30, 20, 22, 4, 21};
    int D2 = 6;
    cout << "Minimum workload for task2: " << minWorkload(task2, D2) << endl; // Output: 22

    return 0;
}
