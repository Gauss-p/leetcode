#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> works;
        for (int i=0; i<n; i++){
            works.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(works.begin(), works.end());
        // works存储每一份工作的结束时间、开始时间以及报酬
        sort(endTime.begin(), endTime.end());
        vector<int> dp(n+1);
        dp[0] = 0;
        int res = works[0][2];
        for (int i=0; i<n; i++){
            // dp[i+1] = dp[i];
            auto it = upper_bound(endTime.begin(), endTime.end(), works[i][1]);
            // for (int j=0; j<it-endTime.begin(); j++){
            //     dp[i] = max(dp[i], dp[j]+works[i][2]);
            // }
            dp[i+1] = max(dp[i], dp[it-endTime.begin()]+works[i][2]);
            // res = max(res, dp[i+1]);
        }
        // for (int i : dp){
        //     cout << i << " ";
        // }
        return dp[n];
    }
};

int main(){
    Solution s;
    vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
    cout << s.jobScheduling(startTime, endTime, profit) << endl;
}
