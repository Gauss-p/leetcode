#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int FREE, HOLD, SELL;
public:
    long long maximumProfit(vector<int>& prices, int k) {
        FREE = 0;
        HOLD = 1;
        SELL = 2;
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(3, 0)));
        for (int j=0; j<=k; j++){
            dp[0][j][HOLD] = -prices[0];
            dp[0][j][SELL] = prices[0];
        }

        for (int i=1; i<n; i++){
            for (int j=1; j<=k; j++){
                dp[i][j][FREE] = max(dp[i-1][j][FREE], max(dp[i-1][j][SELL]-prices[i], dp[i-1][j][HOLD]+prices[i]));
                dp[i][j][SELL] = max(dp[i-1][j][SELL], dp[i-1][j-1][FREE]+prices[i]);
                dp[i][j][HOLD] = max(dp[i-1][j][HOLD], dp[i-1][j-1][FREE]-prices[i]);
            }
        }
        return dp[n-1][k][FREE];
    }
};

int main(){
    Solution s;
    vector<int> prices = {1,7,9,8,2};
    int k = 2;
    cout << s.maximumProfit(prices, k) << endl;
}
