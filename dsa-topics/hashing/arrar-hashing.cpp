#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Input size of array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 2: Precompute frequencies (hashing)
    // assuming numbers are between 0 and 12
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    // Step 3: Answer queries
    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }

    return 0;
}
 