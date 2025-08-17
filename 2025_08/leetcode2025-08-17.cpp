#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double tot = 0;
        vector<double> dp(k+maxPts, 0);
        for (int i=k; i<=k+maxPts-1; i++){
            if (i<=n){
                dp[i] = 1.0;
                tot += 1.0;
            }
        }

        for (int i=k-1; i>=0; i--){
            dp[i] = tot/(1.0*maxPts);
            tot += dp[i];
            tot -= dp[i+maxPts];
        }
        return dp[0];
    }
};

int main(){
    Solution s;
    int n = 6, k = 1, maxPts = 10;
    cout << s.new21Game(n, k, maxPts) << endl;
}
