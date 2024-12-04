#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> findAllDistinctSubsets(vector<int>& arr) {
    // Sort the array to handle duplicates
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    set<vector<int>> uniqueSubsets;

    // Total number of subsets is 2^n
    int totalSubsets = 1 << n; // 2^n

    for (int mask = 0; mask < totalSubsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is set in mask
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        // Insert the subset into the set to ensure uniqueness
        uniqueSubsets.insert(subset);
    }

    // Convert the set of subsets into a vector of vectors
    return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
}

int main() {
    // Input test case 1
    vector<int> arr1 = {1, 2, 2};
    vector<vector<int>> subsets1 = findAllDistinctSubsets(arr1);

    cout << "Distinct subsets for {1, 2, 2}:\n";
    for (const auto& subset : subsets1) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    // Input test case 2
    vector<int> arr2 = {1, 2};
    vector<vector<int>> subsets2 = findAllDistinctSubsets(arr2);

    cout << "\nDistinct subsets for {1, 2}:\n";
    for (const auto& subset : subsets2) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
