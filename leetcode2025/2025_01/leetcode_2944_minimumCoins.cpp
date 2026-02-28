#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, INT_MAX);
        for (int i=(n+1)/2-1; i<n; i++){
            dp[i] = prices[i];
        }
        for (int i=(n+1)/2-1; i>0; i--){
            int tmp = INT_MAX;
            for (int j=i; j<=2*i; j++){
                tmp = min(tmp, dp[j]);
            }
            dp[i-1] = prices[i-1]+tmp;
        }
        return dp[0];
    }
};

int main(){
    Solution s;
    vector<int> prices = {1,10,1,1};
    cout << s.minimumCoins(prices) << endl;
}
