#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int profit(vector<int>& prices) 
{
    int n = prices.size();
    
    if (n == 0) 
    {
        return 0;
    }
    

    int minPrice = prices[0]; 
    int maxProfit = 0;        

    for (int i = 1; i < n; i++) 
    {
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main() 
{
    vector<int> prices1 = {2, 3, 5};
    vector<int> prices2 = {8, 5, 1};

    cout << "Max profit for prices1: " << profit(prices1) << endl;
    cout << "Max profit for prices2: " << profit(prices2) << endl;

    return 0;
}
