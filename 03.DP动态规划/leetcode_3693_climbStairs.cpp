#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        vector<int> dp(3, INT_MAX/2);
        dp[2] = 0;
        for (int i=1; i<=n; i++){
            int cur = INT_MAX/2;
            for (int j=1; j<=min(i, 3); j++){
                cur = min(cur, dp[3-j]+costs[i]+j*j);
            }
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = cur;
        }
        return dp[2];
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<int> costs = {1,2,3,4};
    cout << s.climbStairs(n, costs) << endl;
}
