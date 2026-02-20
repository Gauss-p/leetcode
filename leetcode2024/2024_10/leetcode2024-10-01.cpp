#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n = days.size();
        // vector<int> dp(days[n-1], 0);
        // unordered_set<int> st(days.begin(), days.end());
        // for (int d = days[n-1]; d >= days[0]; d--){
        //     if (st.count(d)){

        //     }
        // }
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        int indx = 0;
        for (int i=1; i<=365; i++){
            if (indx < days.size() && i == days[indx]){
                // 对两种情况分别处理，第一种是在第0天买票直接可以覆盖到第i天，第二种是通过之前的某一天买票覆盖到第i天
                // 以下是第一种情况
                if (i <= 1){

                    dp[i] = min(dp[i], dp[0]+costs[0]);
                }
                if (i <= 7){
                    dp[i] = min(dp[i], dp[0]+costs[1]);
                }
                if (i <= 30){
                    dp[i] = min(dp[i], dp[0]+costs[2]);
                }
                // 以下是第二种情况
                if (i-1 > 0){
                    dp[i] = min(dp[i], dp[i-1]+costs[0]);
                }
                if (i-7 > 0){
                    dp[i] = min(dp[i], dp[i-7]+costs[1]);
                }
                if (i-30 > 0){
                    dp[i] = min(dp[i], dp[i-30]+costs[2]);
                }
                indx++;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};

int main(){
    Solution s;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,5};
    cout << s.mincostTickets(days, costs) << endl;
}
