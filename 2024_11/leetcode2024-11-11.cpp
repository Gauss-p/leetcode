#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // 用动态规划的思路，定义dp[i][j]表示从cuts[i]切到cuts[j]的最低成本，为了方便计算，我们将木棍的起始点和终点都加入cuts数组中，也就是0和n，然后排序。如果cuts数组最开始的长度为m，那么加入后的长度就是m+2，并且最终需要返回的答案就是dp[1][m]，因为我们不需要切cuts[0]和cuts[m+1]，这只是木棍的起点和终点
        // 接下来的递推式，对于dp[i][j]，我们可以循环从i到j的每一个切割标记，记为k，枚举第一刀的位置，如果为cuts[k]，那么从i~j这一段被分成i~k-1和k+1~j两段变成了两个子问题转移方程为：dp[i][j] = min(dp[i][k-1] + dp[k+1][j]) + (cuts[j+1]-cuts[i-1])其中k为从i~j进行遍历，(cuts[j+1]-cuts[i-1])是被切割的木棍长度
        // 最后来判断边界条件，当i>j时，dp[i][j]=0，因为此时我们的起点已经在终点后面。需要注意的是，i的循环方式要从后往前循环，因为如果正向循环，那么在计算dp[i][j]的时候，用到的dp[k+1][j]是在i计算之后才能计算的，这回使得数据缺少
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        for (int i=m; i>=1; i--){
            for (int j=i; j<=m; j++){
                if (i == j){
                    // 边界条件
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = INT_MAX;
                }
                for (int k=i; k<=j; k++){
                    // 枚举第一刀的位置，求最小值
                    dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j] += (cuts[j+1]-cuts[i-1]);
            }
        }
        return dp[1][m];
    }
};

int main(){
    Solution s;
    vector<int> cuts = {1,3,4,5};
    int n = 7;
    cout << s.minCost(n, cuts) << endl;
}
