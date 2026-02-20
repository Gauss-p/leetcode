#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i=n-2; i>=0; i--){
            for (int j=i+1; j<n; j++){
                cost[i][j] = cost[i+1][j-1];
                if (s[i]!=s[j]){
                    cost[i][j]++;
                }
            }
        }
        
        int k = 3;
        vector<int> dp;
        dp = cost[0];
        for (int i=1; i<k; i++){
            for (int r=n-(k-i); r>=i; r--){
                int tmp = INT_MAX/2;
                for (int l=i; l<=r; l++){
                    tmp = min(tmp, dp[l-1]+cost[l][r]);
                }
                dp[r] = tmp;
            }
        }
        return dp[n-1]==0;
    }
};

int main(){
    Solution sl;
    string s = "abcbdd";
    cout << sl.checkPartitioning(s) << endl;
}
