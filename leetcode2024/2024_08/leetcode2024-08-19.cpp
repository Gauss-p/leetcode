#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        // 对于这道题目，我们首先可以考虑动态规划，读题可以发现，拿不拿全勤奖和记录中的"p"没有任何关系，我们需要考虑的只有"A"的个数和连续的"L"的个数
        // 那么我们定义dp[i][a][l]表示当时间来到第i天时，一共累计了a天缺席以及l天迟到，那么可以知道，答案就是dp[n][0][0]+dp[n][0][1]+dp[n][0][2]+dp[n][1][0]+dp[n][1][1]+dp[n][1][2]
        // 接下来要写出递推关系式，我们发现，任何的dp[i][a][l](l>=1)都只和dp[i-1][a][l-1]有关，所以这几项直接传下去即可，我们只需考虑dp[i][0][0]和dp[i][1][0]这两种情况
        // 可以发现，如果到第i天累计0天缺席和0天迟到，那么第i-1天时一定只累计了0天缺席，而迟到天数有可能是0或1或2，如果到第i天累计1天缺席和0天迟到，那么第i-1天时可能累计0或1天缺席以及0或1或2天迟到
        // 为了节省空间，我们可以用两个二维列表滚动求解
        vector<vector<int>> dp_last(2, vector<int>(3, 0)), dp_cur(2, vector<int>(3, 0));
        dp_last[0][0] = 1;
        int mod_num = 1e9+7;
        for (int i=1; i<=n; i++){
            dp_cur[0][0] = (1ll*dp_last[0][0]+1ll*dp_last[0][1]+1ll*dp_last[0][2])%mod_num;
            dp_cur[0][1] = dp_last[0][0]%mod_num;
            dp_cur[0][2] = dp_last[0][1]%mod_num;
            dp_cur[1][0] = (1ll*dp_last[0][0]+1ll*dp_last[0][1]+1ll*dp_last[0][2]+1ll*dp_last[1][0]+1ll*dp_last[1][1]+1ll*dp_last[1][2])%mod_num;
            dp_cur[1][1] = dp_last[1][0]%mod_num;
            dp_cur[1][2] = dp_last[1][1]%mod_num;
            dp_last = dp_cur;
        }
        return (1ll*dp_cur[0][0]+1ll*dp_cur[0][1]+1ll*dp_cur[0][2]+1ll*dp_cur[1][0]+1ll*dp_cur[1][1]+1ll*dp_cur[1][2])%mod_num;
    }
    
    long long maximumValueSum(vector<vector<int>>& board) {
        vector<vector<int>> points;
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                points.push_back({board[i][j], i, j});
            }
        }
        sort(points.begin(), points.end(), greater<vector<int>>());
        long long res = LLONG_MIN;
        for (int i=0; i<m*n; i++){
            int v1 = points[i][0], x1 = points[i][1], y1 = points[i][2];
            if (1ll*v1*3 <= res){
                return res;
            }
            for (int j=i+1; j<m*n; j++){
                int v2 = points[j][0], x2 = points[j][1], y2 = points[j][2];
                if (x2 == x1 || y2 == y1){
                    continue;
                }
                if (1ll*v1+1ll*2*v2 <= res){
                    break;
                }
                for (int k=j+1; k<m*n; k++){
                    int v3 = points[k][0], x3 = points[k][1], y3 = points[k][2];
                    if (x3 == x1 || x3 == x2 || y3 == y1 || y3 == y2){
                        continue;
                    }
                    if (1ll*v1+1ll*v2+1ll*v3 <= res){
                        break;
                    }
                    res = max(res, 1ll*v1+1ll*v2+1ll*v3);
                }
            }
        }
        return res;
        // int m = board.size(), n = board[0].size();
        // vector<int> visitedRow(m, 0);
        // auto dfs = [&](auto&& dfs, int col, int leave, long long score){
        //     if (leave == 0){
        //         return score;
        //     }
        //     long long tmp = INT_MIN;
        //     for (int j=col; j<=n-leave; j++){
        //         for (int i=0; i<m; i++){
        //             if (visitedRow[i] == 0){
        //                 visitedRow[i] = 1;
        //                 tmp = max(tmp, dfs(dfs, j+1, leave-1, score+board[i][j]));
        //                 visitedRow[i] = 0;
        //             }
        //         }
        //     }
        //     return tmp;
        // };
        // return dfs(dfs, 0, 3, 0);
    }
};

int main(){
    Solution s;
    int n = 10101;
    cout << s.checkRecord(n) << endl;
    // ---------------------------------
    vector<vector<int>> board = {{-3,1,1,1},{-3,1,-3,1},{-3,2,1,1}};
    cout << s.maximumValueSum(board) << endl;
}
