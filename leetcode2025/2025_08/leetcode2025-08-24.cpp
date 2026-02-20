#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int l = 0, cnt0 = 0, cnt1 = 0;
        for (int r=0; r<n; r++){
            cnt0 += (1-nums[r]);
            cnt1 += nums[r];
            while (l<=r && cnt0>1){
                cnt0 -= (1-nums[l]);
                cnt1 -= nums[l];
                l++;
            }
            res = max(res, cnt1);
        }
        return res==n ? res-1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1};
    cout << s.longestSubarray(nums) << endl;
}
