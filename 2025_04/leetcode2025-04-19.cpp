#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        for (int i=0; i<n; i++){
            int l = lower-nums[i];
            int r = upper-nums[i];
            int leftIndx = max(i+1, (int)(lower_bound(nums.begin(), nums.end(), l)-nums.begin()));
            int rightIndx = upper_bound(nums.begin(), nums.end(), r)-nums.begin()-1;
            res += max(0, rightIndx-leftIndx+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3, upper = 6;
    cout << s.countFairPairs(nums, lower, upper) << endl;
}
