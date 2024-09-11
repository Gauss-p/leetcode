#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        // 思路如下，因为我们要选择两个长度为k的子序列，同时还需要保证答案最大，我们就需要尽量保证两个数组没有重复的部分，所以对于每一个奖品，我们都可以在它的左边搜索长度为k的子序列的最大和，以及它右边的长度为k的子序列的最大和，所以可以提前处理好左边的子序列最大和，右边的直接在遍历i的时候计算即可
        int n = pos.size();
        vector<int> dp(n, 0);
        int j=0;
        int cnt = 0;
        for (int i=0; i<n; i++){
            cnt++;
            while (j<=i && pos[i]-pos[j] > k){
                cnt--;
                j++;
            }
            dp[i] = cnt;
            // 计算出来每一个奖品的左边k个位置的奖品数量和
        }
        for (int i=1; i<n; i++){
            if (dp[i-1] > dp[i]){
                dp[i] = dp[i-1];
            }
            // 每一个奖品都取它左边的最大值
        }
        j = n-1;
        cnt = 0;
        int res = 0;
        for (int i=n-1; i>=0; i--){
            cnt++;
            // 计算右边的k长度子序列的和
            while (j>=i && pos[j]-pos[i] > k){
                cnt--;
                j--;
            }
            res = max(res, cnt+(i==0 ? 0 : dp[i-1]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> pos = {1,1,2,2,3,3,5};
    int k = 2;
    cout << s.maximizeWin(pos, k) << endl;
}
