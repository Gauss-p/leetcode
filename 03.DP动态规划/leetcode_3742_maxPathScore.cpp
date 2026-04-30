#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int KK) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(KK+1, INT_MIN)));
        dp[0][0] = vector<int>(KK+1, 0);
        vector<vector<int>> dirs = {{1,0}, {0,1}};
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 && j==0){
                    continue;
                }
                for (int curCost=0; curCost<=KK; curCost++){
                    int lastCost = curCost-(grid[i][j]>0);
                    if (lastCost < 0){
                        continue;
                    }
                    for (int d=0; d<2; d++){
                        int di=dirs[d][0], dj=dirs[d][1];
                        int li=i-di, lj=j-dj;
                        if (li<0 || li>=m || lj<0 || lj>=n){
                            continue;
                        }
                        if (dp[li][lj][lastCost] == INT_MIN){
                            continue;
                        }
                        int curScore = dp[li][lj][lastCost]+grid[i][j];
                        if (curScore > dp[i][j][curCost]){
                            dp[i][j][curCost] = curScore;
                        }
                    }
                }
            }
        }
        int res = *max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
        return res==INT_MIN ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1},{2,0}};
    int k = 1;
    cout << s.maxPathScore(grid, k) << endl;
}
