#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i=1; i<=target; i++){
            for (int j : nums){
                if (j <= i && (dp[i] < INT_MAX-dp[i-j])){
                    dp[i] += dp[i-j]; 
                }
            }
        }
        return dp[target];
        // function<void(int, int)> dfs = [&](int lastSub, int presentNum){
        //     presentNum -= lastSub;
        //     if (presentNum == 0){
        //         // 如果正好减完，那么这是一个有效的组成方式
        //         res++;
        //         return;
        //     }
        //     if (presentNum < 0){
        //         return;
        //     }
        //     for (int i : nums){
        //         // 如果能够继续减，那么就继续递归，减少target
        //         // cout << i << endl;
        //         dfs(i, presentNum);
        //     }
        // };
        // dfs(0, target);
        // return res;
    }
};
