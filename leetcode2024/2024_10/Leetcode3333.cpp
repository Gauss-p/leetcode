#include <iostream>
#include <string>
#include <vector>
using namespace std;

// #pragma GCC optimize(3, "Ofast", "inline");
// auto _{[]() noexcept {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return nullptr;
// }()};
class Solution {
public:
    int possibleStringCount(string word, int k) {
        // 最开始，如果字符串的总长度还没有到达k，就意味着无论怎样选都无法选到长度k，答案就是0
        // 之后，我们分两部分考虑，首先，对于原字符串，我们可以将其划分为很多个连续的重复块，比如说aabbccdd就可以被我们拆分成aa,bb,cc,dd，如果不考虑k的问题，那么总共的可能数就是所有重复块的长度的乘积，因为对于每一个重复块，可能的情况都有该重复块的长度数。例如，对于重复块aa，就有两种情况a和aa。所以将所有重复块的长度相乘，就可以计算出总情况数，我们将它记为res。
        // 接下来考虑一种特殊情况，如果k没有超过重复块的总数，也就说明无论我们怎样设计·可能的字符串·，它的长度都一定大于等于k，这时候直接返回刚才计算出来的res即可
        // 如果不是以上的特殊情况，我们就需要计算长度小于k的·可能的字符串·的情况总数，用res减去长度小于等于k的情况，剩下的就是长度大于等于k的情况总数。为了计算长度小于k的情况总数，我们可以用背包问题的思路解决。首先定义dp[i][j]表示：在前i组连通块中，能够组成长度为j的·可能的字符串·的情况总数。所以i的最大值就是m(m为重复块的总数)，j的最大值就是k-1。
        // 我们已经知道第i组连通块的长度，也就是在前i组联通块中，第i组可能参与到长度为j的·可能的字符串·的情况数。我们称，第i组连通块的长度为c，那么在最终组成的答案中，有可能有1,2,...,c个属于第i组的字符参与进去，又因为我们已经限定了最终组成的字符串的长度是j，所以dp[i+1][j]就有可能是由以下数据转移过来的:dp[i][j-1],dp[i][j-2],dp[i][j-3],...,dp[i][j-c]这时候要注意，我们要保证第二个索引大于0才可以继续计算。也就是说，dp[i+1][j] = dp[i][j-1]+dp[i][j-2]+...+dp[i][max(j-c, 0)]，根据这个递推式，我们可以想到用前缀和进行优化，定义s数组为dp[i]的前缀和，那么dp[i][j] = s[j]-s[max(j-c, 0)]
        // 最后，长度小于k的·可能的字符串·的情况总数就是dp[m][m]+dp[m][m+1]+...+dp[m][k-1]，计算之后用res减去即可得到答案
        int n = word.size();
        if (n < k){
            return 0;
        }
        vector<int> cnt;
        int tmpCnt = 0;
        int modNum = 1e9+7;
        long long res = 1;
        for (int i=0; i<n; i++){
            tmpCnt++;
            if (i == n-1 || word[i] != word[i+1]){
                // 遇到一个重复块的结尾
                cnt.push_back(tmpCnt);
                res = (1ll*res*tmpCnt)%modNum; // 计算答案
                tmpCnt = 0;
            }
        }
        int m = cnt.size();
        if (m >= k){
            // 无论如何都可以凑成，直接返回答案即可
            return res;
        }
        vector<vector<int>> dp(m+1, vector<int>(k, 0));
        dp[0][0] = 1;
        for (int i=0; i<m; i++){
            vector<long long> tmpFrontSum(k+1, 0);// 计算前缀和
            for (int j=0; j<k; j++){
                tmpFrontSum[j+1] = (tmpFrontSum[j]+dp[i][j])%modNum;
            }
            for (int j=i+1; j<k; j++){
                // 考虑在第i个重复块的所有选择方案
                dp[i+1][j] = (tmpFrontSum[j]-tmpFrontSum[max(0, j-cnt[i])])%modNum;
            }
        }
        long long lessThanK = 0; // 计算长度小于k的·可能的字符串·的总数
        for (int i=m; i<k; i++){
            lessThanK = (lessThanK+dp[m][i])%modNum;
        }
        res -= lessThanK;
        return (res%modNum + modNum)%modNum; // 防止出现负数
    }
};

int main(){
    Solution s;
    string word = "aabbccdd";
    int k = 7;
    cout << s.possibleStringCount(word, k) << endl;
    return 0;
}
