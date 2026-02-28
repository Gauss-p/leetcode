#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int modNum = 1e9+7;
        vector<long long> dp(n+1, 0);
        dp[1] = 1;
        for (int i=2; i<=n; i++){
            dp[i] = (dp[i-1]+(dp[(i-delay+n+1)%(n+1)]-dp[(i-forget+n+1)%(n+1)]+modNum))%modNum;
        }
        return (dp[n]-dp[n-forget]+modNum)%modNum;
    }
};

int main(){
    Solution s;
    int n = 6, delay = 2, forget = 4;
    cout << s.peopleAwareOfSecret(n, delay, forget) << endl;
}
