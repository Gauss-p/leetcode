#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i=n-2; i>=0; i--){
            for (int j=i+1; j<n; j++){
                cost[i][j] = cost[i+1][j-1]+(s[i]==s[j] ? 0 : 1);
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX/2));
        for (int i=1; i<=n; i++){
            for (int j=1; j<=k && j<=i; j++){
                if (j == 1){
                    dp[i][j] = cost[0][i-1];
                }
                for (int i0=0; i0<i; i0++){
                    dp[i][j] = min(dp[i][j], dp[i0][j-1]+cost[i0][i-1]);
                }
            }
        }
        return dp[n][k];
    }
};

int main(){
    Solution sl;
    string s = "abc";
    int k = 2;
    cout << sl.palindromePartition(s, k) << endl;
}
