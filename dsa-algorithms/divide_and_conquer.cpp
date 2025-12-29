#include <iostream>
#include <vector>
using namespace std;

/*
    Divide & Conquer (Simple Recursive Sort)

    Idea:
    - Divide array into two halves
    - Recursively sort both halves
    - Combine by merging

    Time: O(n log n)
    Space: O(n)
*/

vector<int> sortVector(vector<int> a) {
    // base case: already sorted
    if (a.size() <= 1) return a;

    int mid = a.size() / 2;

    // divide
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    // conquer
    left = sortVector(left);
    right = sortVector(right);

    // combine (merge)
    vector<int> res;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
        res.push_back(left[i] <= right[j] ? left[i++] : right[j++]);

    while (i < left.size()) res.push_back(left[i++]);
    while (j < right.size()) res.push_back(right[j++]);

    return res;
}

int main() {
    vector<int> a = {5, 3, 8, 1, 2};

    a = sortVector(a);

    for (int x : a) cout << x << " ";
    return 0;
}
