#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) sum += i;
        if ((sum-target)%2 != 0 || sum < target) return 0;
        int negative = (sum-target)/2;
        vector<vector<int>> dp(n+1, vector<int>(negative+1, 0));
        // int dp[n+1][negative+1];
        // for (int i=0; i<=n; i++){
        //     for (int j=0; j<=negative; j++){
        //         dp[i][j] = 0;
        //     }
        // }
        dp[0][0] = 1;
        for (int i=1; i<=n; i++){
            int tmp = nums[i-1];
            for (int j=0; j<=negative; j++){
                dp[i][j] = dp[i-1][j];
                if (j >= tmp){
                    dp[i][j] += dp[i-1][j-tmp];
                }
            }
        }
        return dp[n][negative];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl;
}
