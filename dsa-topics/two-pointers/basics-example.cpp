#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------
1) TWO POINTERS
Problem: Check if sorted array has pair with target sum
------------------------------------------------
*/
void twoPointers() {
    vector<int> arr = {1, 2, 4, 7, 11, 15};
    int target = 15;

    int l = 0, r = arr.size() - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (sum == target) {
            cout << "Two Pointers -> Found: "
                 << arr[l] << " + " << arr[r] << "\n";
            return;
        }
        else if (sum < target) l++;
        else r--;
    }

    cout << "Two Pointers -> Not Found\n";
}

/*
------------------------------------------------
2) SLIDING WINDOW (FIXED SIZE)
Problem: Maximum sum subarray of size k
------------------------------------------------
*/
void slidingWindowFixed() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int l = 0, windowSum = 0, maxSum = 0;

    for (int r = 0; r < nums.size(); r++) {
        windowSum += nums[r];           // add right

        if (r - l + 1 == k) {
            maxSum = max(maxSum, windowSum);
            windowSum -= nums[l];       // remove left
            l++;
        }
    }

    cout << "Fixed Window -> Max Sum: " << maxSum << "\n";
}

/*
------------------------------------------------
3) SLIDING WINDOW (DYNAMIC SIZE)
Problem: Smallest subarray with sum >= target
------------------------------------------------
*/
void slidingWindowDynamic() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int l = 0, sum = 0, minLen = INT_MAX;

    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];                 // expand

        while (sum >= target) {         // shrink
            minLen = min(minLen, r - l + 1);
            sum -= nums[l];
            l++;
        }
    }

    cout << "Dynamic Window -> Min Length: "
         << (minLen == INT_MAX ? 0 : minLen) << "\n";
}

int main() {
    twoPointers();
    slidingWindowFixed();
    slidingWindowDynamic();
    return 0;
}
