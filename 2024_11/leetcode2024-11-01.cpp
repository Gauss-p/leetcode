#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& eA, vector<int>& eB) {
        int n = eA.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        // 定义dp[i][0]表示在第i时间喝饮料A能够获得的最大强化能量，dp[i][1]表示在第i时间喝饮料B能够获得的最大强化能量
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i=1; i<=n; i++){
            // 根据题目，在第i时间如果要选择一种饮料喝，那么上一次喝的有两种情况，要么是在时间i-1的时候选择同一种饮料，要么就得在时间i-2的时候选择另一种饮料
            dp[i][0] = dp[i-1][0]+eA[i-1];
            if (i >= 2){
                dp[i][0] = max(dp[i][0], dp[i-2][1]+eA[i-1]);
            }
            dp[i][1] = dp[i-1][1]+eB[i-1];
            if (i >= 2){
                dp[i][1] = max(dp[i][1], dp[i-2][0]+eB[i-1]);
            }
        }
        return max(dp[n][0], dp[n][1]);
    }
};

int main(){
    Solution s;
    vector<int> eA = {1,3,1};
    vector<int> eB = {3,1,1};
    cout << s.maxEnergyBoost(eA, eB) << endl;
}
