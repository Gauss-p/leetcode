#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        // 用动态规划的方法，定义dp[i][j]表示在[0,1,...,i]中，逆序对总数量为i个的情况数量
        vector<int> newReq(n, -1);
        int mx = 0;
        for (auto& r : requirements){
            newReq[r[0]] = r[1];
            mx = max(mx, r[1]);
        }
        if (newReq[0] > 0) return 0;
        newReq[0] = 0;
        int modNum = 1e9+7;
        vector<vector<int>> dp(n, vector<int>(mx+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<n; i++){
            int l=0, r=mx;
            if (newReq[i] >= 0){
                l = r = newReq[i];
            }
            for (int j=l; j<=r; j++){
                // 循环当前位置和之前所有位置可能形成的逆序对数量，求和即可
                for (int k=0; k<=min(i, j); k++){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-k])%modNum;
                }
            }
        }
        return dp[n-1][newReq[n-1]];
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> requirements = {{2,2},{0,0}};
    cout << s.numberOfPermutations(n, requirements) << endl;
}
