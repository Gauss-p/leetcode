#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> preSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+prices[i];
        }

        vector<long long> money(n+1, 0);
        for (int i=0; i<n; i++){
            money[i+1] = money[i]+prices[i]*strategy[i];
        }

        long long res = money[n];
        for (int i=0; i<=n-k; i++){
            long long cur = money[i]+(money[n]-money[i+k])+(preSum[i+k]-preSum[i+k/2]);
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> prices = {4,2,8};
    vector<int> strategy = {-1,0,1};
    int k = 2;
    cout << s.maxProfit(prices, strategy, k) << endl;
}
