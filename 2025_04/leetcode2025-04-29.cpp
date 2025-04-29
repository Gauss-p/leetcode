#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int l = 0;
        long long res = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for (int r=0; r<n; r++){
            cnt += (nums[r]==mx);
            while (cnt>=k){
                cnt -= (nums[l]==mx);
                l++;
            }
            res += l;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,3,3};
    int k = 2;
    cout << s.countSubarrays(nums, k) << endl;
}
