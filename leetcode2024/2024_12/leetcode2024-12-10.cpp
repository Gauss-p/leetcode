#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> neibors = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        // 定义dp[i][j]表示第i步走到数字j的位置时的总方案数
        vector<vector<int>> dp(n+1, vector<int>(10));
        int modNum = 1000000007;
        for (int i=0; i<10; i++){
            dp[1][i] = 1;
        }
        for (int i=2; i<=n; i++){
            for (int j=0; j<10; j++){
                for (int k : neibors[j]){
                    dp[i][j] = (dp[i][j]+dp[i-1][k])%modNum;
                }
            }
        }
        int res = 0;
        for (int&i : dp[n]){
            res = (res+i)%modNum;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3131;
    cout << s.knightDialer(n) << endl;
}
