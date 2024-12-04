#include <iostream>
#include <vector>
using namespace std;

// Helper function to generate subsets
void generateSubsets(vector<int>& arr, vector<int>& currentSubset, int index) {
    // Base case: Print the current subset when we reach the end of the array
    if (index == arr.size()) {
        for (int num : currentSubset) {
            cout << num << " ";
        }
        if (currentSubset.empty()) {
            cout << "//This space denotes a null element.";
        }
        cout << endl;
        return;
    }

    // Include the current element in the subset
    currentSubset.push_back(arr[index]);
    generateSubsets(arr, currentSubset, index + 1);

    // Exclude the current element from the subset (backtracking)
    currentSubset.pop_back();
    generateSubsets(arr, currentSubset, index + 1);
}

// Main function to handle input and initiate the subset generation
int main() {
    // Input array
    vector<int> arr = {1, 2, 3};
    vector<int> currentSubset; // To hold the current subset being generated

    cout << "All subsets of the array:" << endl;
    generateSubsets(arr, currentSubset, 0);

    return 0;
}
