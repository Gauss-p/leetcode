#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        int pric[m+1][n+1]; // 用来存储宽i高j的木块的价值
        memset(pric, 0, sizeof(pric));
        long long dp[m+1][n+1];
        // 我们称右下角为(i行j列的方格)，左上角为(大木块的左上角)的方木块为"中木块"
        // 用来存储中木块最大价值
        for (auto &p : prices){
            pric[p[0]][p[1]] = p[2]; // 存入宽p[0]高p[1]的木块的价值
        }
        for (int i=1; i<=m; i++){
            for (int j=0; j<=n; j++){
                long long tmp = 0;
                // 那么中木块的价值即为：
                // 1.以从左到右第k个小方块的右边缘(或是下边缘)切开大木块
                // 2.左边最大价值加上右边最大价值(或是上面加下面)，即为中木块的价值
                // 3.循环k，就可以求出中木块最大的价值
                for (int k=1; k<j; k++){
                    // 该循环从左到右
                    tmp = max(tmp, dp[i][k]+dp[i][j-k]);
                }
                for (int k=1; k<i; k++){
                    // 该循环从上到下
                    tmp = max(tmp, dp[k][j]+dp[i-k][j]);
                }
                // 如果中木块的价值在prices数组中有直接给出，那么与求出的tmp中取最大值存入
                dp[i][j] = max(1ll*pric[i][j], tmp);
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;
    // int m = 3, n = 5;
    // vector<vector<int>> prices = {{1,4,2},{2,2,7},{2,1,3}};
    int m = 4, n = 6;
    vector<vector<int>> prices = {{3,2,10},{1,4,2},{4,1,3}};
    cout << s.sellingWood(m, n, prices);
}
