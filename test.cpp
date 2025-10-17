#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    for(int i=0; i<nums.size(); i++) {
        int target = -nums[i];
        int l = i+1;
        int r = nums.size()-1;

        while(l<r) {
            // if(l==i) l++;
            // if(r==i) r--;
            if(nums[l]+nums[r] == target) {

                res.push_back({nums[i], nums[l], nums[r]});
                cout<<i<<endl;
                break;
            }

            if(nums[l]+nums[r] < target) l++;
            else if(nums[l]+nums[r] > target) r--;
        }

    }
    return res;

}


int main() {

    vector<int> num = {-1,0,1,2,-1,-4};
    
    threeSum(num);
    return 0;
}
