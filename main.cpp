// HOSTINE OLARE
// EB3/68519/23
// C++ - Simplified Pigeonhole Sort

#include <iostream>
#include <vector>
using namespace std;

void pigeonholeSort(vector<int>& arr, long long& comp, long long& moves) {
    if (arr.empty()) {
        comp = moves = 0;
        return;
    }

    // Find min and max while counting comparisons
    int minVal = arr[0], maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        comp++; // compare with current min
        if (arr[i] < minVal) minVal = arr[i];
        comp++; // compare with current max
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int range = maxVal - minVal + 1;
    vector<int> holes(range, 0);   // frequency array (pigeonholes)

    // Count occurrences – each increment counts as a "move"
    for (int num : arr) {
        holes[num - minVal]++;
        moves++;
    }

    // Rebuild sorted array
    int idx = 0;
    for (int i = 0; i < range; i++) {
        for (int cnt = 0; cnt < holes[i]; cnt++) {
            arr[idx++] = i + minVal;
            moves++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Unsorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    long long comparisons = 0, moves = 0;
    pigeonholeSort(arr, comparisons, moves);

    cout << "Sorted:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Moves (assignments): " << moves << endl;

    return 0;
}