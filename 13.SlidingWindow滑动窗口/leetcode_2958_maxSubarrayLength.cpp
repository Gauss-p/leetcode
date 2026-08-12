#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, r = 0;
        unordered_map<int, int> cnt;
        for (int l=0; l<n; l++){
            while (r<n && cnt[nums[r]]+1 <= k){
                cnt[nums[r]]++;
                r++;
            }
            res = max(res, r-l);
            cnt[nums[l]]--;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;
    cout << s.maxSubarrayLength(nums, k) << endl;
}
