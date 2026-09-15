#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool check(string s){
        string ns;
        for (auto& c : s) ns = c+ns;
        return s==ns;
    }
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i=k; i<=n; i++){
            dp[i] = dp[i-1];
            if (check(s.substr(i-k, k))){
                dp[i] = max(dp[i], dp[i-k]+1);
            }
            if (i>k && check(s.substr(i-k-1, k+1))){
                dp[i] = max(dp[i], dp[i-k-1]+1);
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sl;
    string s = "abaccdbbd";
    int k = 3;
    cout << sl.maxPalindromes(s, k) << endl;
}
