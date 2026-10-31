#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
        int modNum = 1e9+7;
        // 0->下，1->右
        dp[1][0][0] = 1;
        dp[0][1][1] = 1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    dp[i+1][j][0] = (1ll*dp[i+1][j][0]+1ll*dp[i][j][1])%modNum;
                    dp[i][j+1][1] = (1ll*dp[i][j+1][1]+1ll*dp[i][j][0])%modNum;
                }
                else{
                    dp[i+1][j][0] = (1ll*dp[i+1][j][0]+1ll*dp[i][j][0]+1ll*dp[i][j][1])%modNum;
                    dp[i][j+1][1] = (1ll*dp[i][j+1][1]+1ll*dp[i][j][0]+1ll*dp[i][j][1])%modNum;
                }
            }
        }

        return (dp[m-1][n-1][0]+dp[m-1][n-1][1])%modNum;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,0},{0,0,1},{1,0,0}};
    cout << s.uniquePaths(grid) << endl;
}
