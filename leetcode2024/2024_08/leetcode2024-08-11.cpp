#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // 最长子序列问题，定义dp[i][j]表示nums1的前i个数字和nums2的前j个数字中最长的公共子序列长度，那么可以知道，如果nums1[i-1]=nums2[j-1]，那dp[i][j]就是dp[i-1][j-1]+1，否则就是dp[i-1][j]和dp[i][j-1]里的最小值
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for (int i=0; i<=m; i++){
            dp[0][i] = 0;
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (nums1[i] == nums2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,4,2};
    vector<int> nums2 = {1,2,4};
    cout << s.maxUncrossedLines(nums1, nums2) << endl;
}
