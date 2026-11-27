#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i == j){
                    continue;
                }
                if (items[j][0]%items[i][0] == 0){
                    cnt[i] += 1;
                }
            }
        }
        vector<int> dp(budget+1, 0);
        for (int i=0; i<n; i++){
            int p = items[i][1];
            for (int j=budget; j>=p; j--){
                dp[j] = max(dp[j], dp[j-p]+cnt[i]+1);
            }
            for (int j=p; j<=budget; j++){
                dp[j] = max(dp[j-p]+1, dp[j]);
            }
        }
        return dp[budget];
    }
};

int main(){
    Solution s;
    vector<vector<int>> items = {{6, 2}, {2, 6}, {3, 4}};
    int budget = 9;
    cout << s.maximumSaleItems(items, budget) << endl;
}
