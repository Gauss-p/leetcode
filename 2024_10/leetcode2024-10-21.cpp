#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx = INT_MAX, mn = 0;
        int n = nums.size();
        int res = nums[n-1]-nums[0];
        for (int i=0; i<n-1; i++){
            mx = max(nums[i]+k, nums[n-1]-k);
            mn = min(nums[i+1]-k, nums[0]+k);
            res = min(res, mx-mn);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,3,6};
    int k = 2;
    Solution s;
    cout << s.smallestRangeII(nums, k) << endl;
}
