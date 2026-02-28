#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        vector<int> newPower;
        for (int i : power){
            if (cnt[i] == 0){
                newPower.push_back(i);
            }
            cnt[i]++;
        }
        sort(newPower.begin(), newPower.end());
        int n = newPower.size();
        vector<long long> dp(n, 0);
        dp[0] = 1ll*newPower[0]*cnt[newPower[0]];
        int j = -1;
        for (int i=1; i<n; i++){
            dp[i] = dp[i-1];
            while (j+1<i && newPower[i]-newPower[j+1]>2){
                j++;
            }
            if (j >= 0){
                dp[i] = max(dp[i], dp[j]+1ll*newPower[i]*cnt[newPower[i]]);
            }
            else{
                dp[i] = max(dp[i], 1ll*newPower[i]*cnt[newPower[i]]);
            }
        }
        return dp[n-1];
    }
};

int main(){
    Solution s;
    vector<int> power = {1,1,3,4};
    cout << s.maximumTotalDamage(power) << endl;
}
