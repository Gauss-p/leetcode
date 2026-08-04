#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> g(n, vector<bool>(n, true));
        for (int i=n-1; i>=0; i--){
            for (int j=i+1; j<n; j++){
                g[i][j] = (s[i]==s[j] && g[i+1][j-1]);
            }
        }
        vector<int> dp(n, INT_MAX);
        for (int i=0; i<n; i++){
            if (g[0][i]){
                dp[i] = 0;
                continue;
            }
            for (int j=0; j<i; j++){
                if (g[j+1][i]){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

int main(){
    Solution sl;
    string s = "aab";
    cout << sl.minCut(s) << endl;
}
