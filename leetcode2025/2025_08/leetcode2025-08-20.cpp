#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // 也可以考虑动态规划，定义dp[i+1][j+1]表示以(i,j)为右下角的合法正方形个数，也就是最大合法正方形边长，那么只要matrix[i][j]=0，dp[i+1][j+1]就一定是0，否则至少也应该是1.然后，如果要达到一个边长k，那么以(i,j-1)、(i-1,j)、(i-1,j-1)开头的最大边长应当至少为k-1，所以我们就可以得到：dp[i+1][j+1]=1+min(dp[i+1][j],dp[i][j+1],dp[i][j])
        // 最终的答案应当对dp中所有元素求和
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (matrix[i-1][j-1] == 1){
                    dp[i][j] = 1;
                    dp[i][j] += min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        int res = 0;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                res += dp[i][j];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << s.countSquares(matrix) << endl;
}
