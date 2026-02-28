#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int myCount(string& s, char c){
        int res = 0;
        for (auto& i : s){
            res += (i==c);
        }
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto& s : strs){
            int zeros = myCount(s, '0'), ones = myCount(s, '1');
            for (int j=m; j>=zeros; j--){
                for (int k=n; k>=ones; k--){
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;
    vector<string> strs = {"10","0001","111001","1","0"};
    int m=5, n=3;
    cout << s.findMaxForm(strs, m, n) << endl;
}
