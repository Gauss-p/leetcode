#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // 通过0-1背包问题的思路，我们定义dp[i][j]表示在编号在[0...i]中的所有奖励值是否能通过某种选择方式凑成总奖励j，所以可以知道，dp中的所有值要么是0要么是1。那么我们可以将j想象成是一个背包的最大限重，这时，对于每一个待选择奖励就有两种方案，选或不选，如果选择奖励i，那么dp[i][j]能不能放得下就要看dp[i][j-rewardValues[i]]是否为1，而如果不选择奖励i，那么dp[i][j]就可以直接继承dp[i-1][j]的值，又因为dp中所有值在0或1中，所以dp[i][j]就可以看成是dp[i-1][j-rewardValues[i]]|dp[i-1][j]，又因为这里面j的值最小是rewardValues[i]，最大是2*rewardValues[i]所以我们可以将整个计算看成是一个二进制数的最末端两段长度为rewardValues[i]的数据相或即可
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        if (rewardValues.size() >= 2 && rewardValues[n-1] == rewardValues[n-2]+1){
            return rewardValues[n-1]*2-1;
        }
        bitset<100000> f0, f1;
        f0[0] = 1;
        for (int i=0, j=0; i<n; i++){
            while (j < rewardValues[i]){
                f1[j] = f0[j];// 转移上一次已经计算的数据
                j++;
            }
            // 状态转移
            f0 = f0 | (f1 << j);
        }
        int res = 0;
        for (int i=0; i<f0.size(); i++){
            if (f0[i]){
                res = i;
                // 计算最高一位1
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> rewardValues = {1,1,3,3};
    cout << s.maxTotalReward(rewardValues) << endl;
}
