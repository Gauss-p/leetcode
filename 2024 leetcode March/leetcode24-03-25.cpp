#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++){
            for (int j=0; j<=amount; j++){
                if (j-coins[i-1] < 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout << s.change(amount, coins) << endl;
}
