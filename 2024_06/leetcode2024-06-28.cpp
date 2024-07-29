#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // 这个题目可以用动态规划来计算
        // 由题目可以得出，如果花费cost[i]，可以有time[i]+1面墙被粉刷
        // 所以我们将cost[i]看作一个物品的价值，将time[i]+1看作这个物品的体积
        // 那么这个题目就是要我们求在前n个物品中选几个物品，使得它们的体积大于等于n，求这几个物品的最小价值
        // 定义dp[i][j]表示：在前i个物品中选择总体积大于等于j的几个物品，这几个物品的最小价值
        // 那么对于每一个dp[i][j]，我们分两种情况讨论：1.选择第i个物品；2.不选择第i个物品
        // 对于1.，我们可以发现如果选第i个物品后体积大于等于j
        // 那么相当于在前i-1个物品中选择体积大于等于j-(time[i]+1)的几个物品，再加上当前物品
        // 也就是dp[i][j] = dp[i-1][j-(time[i]+1)]
        // 对于2.，我们可以发现如果不选第i个物品，就相当于在前i-1个物品中选
        // 也就是dp[i][j] = dp[i-1][j]
        // 最后求这两个情况的最小值，也就求出准确的dp[i][j]的值了
        // 参照dp[i][j]的定义，最终只需要返回dp[n][n]即可，注意其中的索引会有变动
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX/2));
        for (int i=0; i<n; i++){
            // 在前0面墙中选，无论怎样花费都是0
            dp[i][0] = 0;
        }
        for (int i=1; i<=n; i++){
            for (int j=0; j<=n; j++){
                dp[i][j] = min(dp[i][j], dp[i-1][j]); // 情况1.
                dp[i][j] = min(dp[i][j], dp[i-1][max(0, j-time[i-1]-1)]+cost[i-1]); // 情况2.
            }
        }
        return dp[n][n];
    }
};

int main(){
    Solution s;
    vector<int> cost = {1,2,3,2}, time = {1,2,3,2};
    cout << s.paintWalls(cost, time) << endl;
}
