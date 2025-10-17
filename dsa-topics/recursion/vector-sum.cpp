#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nums= {2,3,7,8, 5};
int n = 0;

int sumAll(int n) {
    if (n == (nums.size()-1)) {         // Base case

        return nums[n];
    }


    return nums[n] + sumAll(n + 1);
}

int main() {

    cout << sumAll(n) <<endl;
    return 0;
}
