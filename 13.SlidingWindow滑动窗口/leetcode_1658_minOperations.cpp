#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        x = -x;
        for (int i : nums) x+=i;
        int r = 0;
        int tot = 0;
        int res = INT_MAX;
        int n = nums.size();
        for (int l=0; l<n; l++){
            while (r<n && tot<x){
                tot += nums[r];
                r++;
            }
            if (tot == x && l <= r){
                res = min(res, n-(r-l));
            }
            tot -= nums[l];
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,4,2,3};
    int x=5;
    cout << s.minOperations(nums, x) << endl;
}
