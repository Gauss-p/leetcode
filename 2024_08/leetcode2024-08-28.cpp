#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        // 用动态规划，定义dp[i]表示在s[0...i-1]中最少可以划分的平衡子字符串，那么我们可以知道，最终返回的答案就是dp[n]。作为初始化，因为要求最小值，所以我们需要将dp中每一个元素都置为INT_MAX，同时dp[0]直接初始化为0
        // 而动态规划最重要的是递推式，可以发现，dp[i]需要从上一个已经计算好的dp[j]得到，而这就需要一个条件：s[i...j]是一个平衡子字符串，这个时候，dp[i]就可以直接计算和dp[j]+1的最小值，更新答案即可
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=n; i++){
            int max_cnt = 0;
            unordered_map<char, int> mp;
            for (int j=i-1; j>=0; j--){
                mp[s[j]]++;
                max_cnt = max(max_cnt, mp[s[j]]);
                if (max_cnt*mp.size() == i-j){
                    dp[i] = min(dp[j]+1, dp[i]);
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution so;
    string s = "fabccddg";
    cout << so.minimumSubstringsInPartition(s) << endl;
}
