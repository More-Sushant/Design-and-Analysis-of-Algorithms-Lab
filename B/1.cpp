#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxShop(vector<int>& S, vector<int>& E, int K) 
{
    int N = S.size();
    vector<pair<int, int>> shops;
    for (int i = 0; i < N; i++) 
    {
        shops.push_back({E[i], S[i]});
    }

    sort(shops.begin(), shops.end());

    vector<int> endTimes(K, 0);
    int count = 0;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < K; j++) 
        {
            if (endTimes[j] <= shops[i].second) 
            {
                endTimes[j] = shops[i].first;
                count++;
                break;
            }
        }
    }

    return count;
}

int main() 
{
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited: " << maxShop(S1, E1, K1) << endl;  

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited: " << maxShop(S2, E2, K2) << endl;

    return 0;
}
