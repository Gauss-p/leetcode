#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](auto&a, auto&b){
            return a[1] < b[1];
        });
        vector<int> endTime;
        for (auto&e : events){
            endTime.push_back(e[1]);
        }
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i=1; i<n+1; i++){
            int start = events[i-1][0], end = events[i-1][1], val = events[i-1][2];
            int indx = lower_bound(endTime.begin(), endTime.end(), start)-endTime.begin()-1;
            for (int j=0; j<=k; j++){
                dp[i][j] = dp[i-1][j];
                if (j>0 && indx+1 < i){
                    dp[i][j] = max(dp[i][j], dp[indx+1][j-1]+val);
                }
            }
        }
        return dp[n][k];
    }
};

int main(){
    Solution s;
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    int k = 2;
    cout << s.maxValue(events, k) << endl;
}
