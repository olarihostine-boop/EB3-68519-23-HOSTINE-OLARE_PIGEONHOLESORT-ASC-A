// HOSTINE OLARE
// EB3/68519/23
// C++

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void pigeonholeSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    if (arr.empty()) return;
    
    comparisons = 0;
    swaps = 0;
    
    // Find min and max with comparison counting
    int min_val = arr[0];
    int max_val = arr[0];
    
    for (size_t j = 1; j < arr.size(); ++j) {
        comparisons++;
        if (arr[j] < min_val) {
            min_val = arr[j];
        } else {
            comparisons++;
            if (arr[j] > max_val) {
                max_val = arr[j];
            }
        }
    }
    
    int range = max_val - min_val + 1;
    
    // Create pigeonholes
    vector<vector<int> > pigeonholes(range);
    
    // Place elements into pigeonholes (count as operations)
    for (size_t j = 0; j < arr.size(); ++j) {
        int num = arr[j];
        pigeonholes[num - min_val].push_back(num);
        swaps++; // count placement as an operation
    }
    
    // Collect from pigeonholes in ascending order
    int index = 0;
    for (int i = 0; i < range; ++i) {
        for (size_t k = 0; k < pigeonholes[i].size(); ++k) {
            int num = pigeonholes[i][k];
            arr[index++] = num;
            swaps++; // count placement back to array as an operation
        }
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the size of the list: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Error: Size must be a positive integer." << endl;
        return 1;
    }
    vector<int> arr(n);
    cout << "Enter " << n << " integers to sort: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Unsorted list: ";
    for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;

    long long comparisons = 0, swaps = 0;
    pigeonholeSort(arr, comparisons, swaps);

    cout << "Sorted list: ";
    for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    return 0;
}