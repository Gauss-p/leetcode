#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            if (obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (int j=0; j<n; j++){
            if (obstacleGrid[0][j]) break;
            dp[0][j] = 1;
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (obstacleGrid[i][j] == 1) continue;
                if (obstacleGrid[i-1][j] != 1) dp[i][j] += dp[i-1][j];
                if (obstacleGrid[i][j-1] != 1) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}
