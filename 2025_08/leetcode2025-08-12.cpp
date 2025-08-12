#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        int modNum = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++){
            long long curPow = pow(i, x);
            for (int j=0; j<=n; j++){
                dp[i][j] = dp[i-1][j];
                if (j>=curPow){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-curPow])%modNum;
                }
            }
        }
        return dp[n][n];
    }
};

int main(){
    Solution s;
    int n = 10, x = 2;
    cout << s.numberOfWays(n, x) << endl;
}
