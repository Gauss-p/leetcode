#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // 定义dp列表，dp[i][j]值为:在前i个栈中取j次，所能够取得的最大面值之和
        // 那么该值有两种情况，第一种是不选第i-1栈中的元素，那么其值为dp[i-1][j]，第二种是选第i-1栈中的元素，假设在x栈中选[0...k]对应的元素，并且记录这些元素的和tmp，那么dp[i-1][j]的值就是dp[i-1][j-k-1]+tmp，循环k的所有可能值并记录dp[i][j]的最大值即可
        // 最终答案即为dp[n][k]
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i=1; i<=n; i++){
            for (int j=1; j<=k; j++){
                dp[i][j] = dp[i-1][j]; // 选
                int tmp = 0;
                for (int k=0; k<min(j, (int)piles[i-1].size()); k++){
                    tmp += piles[i-1][k];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k-1]+tmp); // 不选
                }
            }
        }
        return dp[n][k];
    }
};

int main(){
    Solution s;
    vector<vector<int>> piles = {{1,100,3}, {7,8,9}};
    int k = 2;
    cout << s.maxValueOfCoins(piles, k) << endl;
}
