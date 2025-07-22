#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int curSum = 0;
        int res = 0;
        unordered_map<int, int> cnt;
        for (int l=0; l<n; l++){
            while (r<n && cnt[nums[r]] == 0){
                cnt[nums[r]]++;
                curSum += nums[r];
                r++;
            }
            res = max(res, curSum);
            cnt[nums[l]]--;
            curSum -= nums[l];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,4,5,6};
    cout << s.maximumUniqueSubarray(nums) << endl;
}
