#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        // 定义dp[i][j]表示从grid[0][0]开始到grid[i-1][j-1]的最小值，那么以grid[i-1][j-1]为结尾的最大得分就是grid[i][j]-dp[i-1][j-1]
        // 而每一次计算dp[i][j]的时候，要么它是从上面下来的，要么是从左边过来的，所以它就是dp[i][j-1]和dp[i-1][j]的最小值
        int res = INT_MIN;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int tmp = min(dp[i+1][j], dp[i][j+1]);
                res = max(res, grid[i][j]-tmp);
                dp[i+1][j+1] = min(grid[i][j], tmp);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    cout << s.maxScore(grid) << endl;
}
