#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        long long curSum = 0;
        long long res = 0;
        for (int r=0; r<n; r++){
            curSum += nums[r];
            while (curSum*(r-l+1)>=k){
                curSum -= nums[l];
                l += 1;
            }
            res += (r-l+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,4,3,5};
    int k = 10;
    cout << s.countSubarrays(nums, k) << endl;
}
