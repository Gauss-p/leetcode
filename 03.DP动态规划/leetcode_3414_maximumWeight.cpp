#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i=0; i<n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), [&](auto&a, auto&b){
            return a[1] < b[1];
        });
        vector<int> rights;
        for (auto& i : intervals){
            rights.push_back(i[1]);
        }
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(5, {0}));
        for (int i=1; i<=n; i++){
            int l = intervals[i-1][0], r = intervals[i-1][1], w = intervals[i-1][2], indx = intervals[i-1][3];
            int last = lower_bound(rights.begin(), rights.end(), l)-rights.begin();
            for (int j=1; j<=4; j++){
                vector<long long> ans = dp[i-1][j];
                long long sc = ans.back();
                ans.pop_back();

                vector<long long> previous = dp[last][j-1];
                long long curScore = previous.back();
                previous.pop_back();
                previous.push_back(indx);
                sort(previous.begin(), previous.end());
                curScore += w;
                if (curScore > sc){
                    ans = previous;
                    sc = curScore;
                }
                else if (curScore == sc){
                    if (ans.size()==0 || ans > previous){
                        ans = previous;
                    }
                }
                ans.push_back(sc);

                dp[i][j] = ans;
            }
        }
        vector<int> res;
        for (int i=0; i<dp[n][4].size()-1; i++){
            res.push_back((int)dp[n][4][i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3,2},{4,5,2},{1,5,5},{6,9,3},{6,7,1},{8,9,1}};
    vector<int> res = s.maximumWeight(intervals);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
