#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), l = k, r = k, res = 0;
        for (int i=nums[k]; i>=1; i--){
            while (l>=0 && nums[l]>=i) l--;
            while (r<n && nums[r]>=i) r++;
            res = max(res, (r-l-1)*i);
            if (l<0 && r == n) break;
        }
        return res;
        // -------------------------------------------------------------
        // int n = nums.size();
        // int res = 0;
        // for (int i=0; i<n; i++){
            // if (i > k) break;
            // vector<int> dp(n);
            // dp[0] = nums[i];
            // for (int j=1; j<n-i; j++){
                // dp[j] = min(dp[j-1], nums[i+j]);
                // if (i<=k && i+j>=k) res = max(res, dp[j]*(j+1));
            // }
        // }
        // res = max(res, nums[k]);
        // return res;
        // -------------------------------------------------------------
        // int n = nums.size();
        // vector<vector<int>> dp(n);
        // int res = 0;
        // for (int i=0; i<n; i++){
            // dp[i].resize(n-i);
            // dp[i][0] = nums[i];
        // }
        // for (int i=0; i<n; i++){
            // for (int j=1; j<n-i; j++){
                // dp[i][j] = min(dp[i][j-1], nums[i+j]);
                // if (i<=k && i+j>=k) res = max(res, dp[i][j]*(j+1));
            // }
        // }
        // res = max(res, nums[k]);
        // return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,3,7,4,5};
    int k = 3;
    // vector<int> nums = {5,5,4,5,4,1,1,1};
    // int k = 0;
    cout << s.maximumScore(nums, k) << endl;
}
