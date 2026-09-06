#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<unsigned>> dp(m+1, vector<unsigned>(n+1, 0));
        for (int j=0; j<=n; j++){
            dp[0][j] = 1;
        }

        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                dp[i][j] = dp[i][j-1];
                if (t[i-1] == s[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution sl;
    string s = "rabbbit", t = "rabbit";
    cout << sl.numDistinct(s, t) << endl;
}
