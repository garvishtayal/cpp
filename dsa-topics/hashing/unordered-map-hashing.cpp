#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Input size and array
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 2: Create an unordered_map for frequency hashing
    unordered_map<int, int> hash;

    // Step 3: Precompute frequency
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // Step 4: Query section
    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;

        // If number exists in map, print its count, else 0
        cout << hash[number] << endl;
    }

    return 0;
}



//NeetCode code to check Duplicate
    bool hasDuplicate(vector<int>& nums) {


        //hash map for nums array
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++) {
            hash[nums[i]]++;
        }

        //check if any duplicate value in hash map
        for(auto &p : hash) {
            if(p.second > 1) return true;
        }

        return false;

    }
