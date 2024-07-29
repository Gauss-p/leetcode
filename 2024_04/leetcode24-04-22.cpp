#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i=1; i<=target; i++){
            for (int j : nums){
                if (j <= i && (dp[i] < INT_MAX-dp[i-j])){
                    dp[i] += dp[i-j]; 
                }
            }
        }
        return dp[target];
        // function<void(int, int)> dfs = [&](int lastSub, int presentNum){
        //     presentNum -= lastSub;
        //     if (presentNum == 0){
        //         // ������ü��꣬��ô����һ����Ч����ɷ�ʽ
        //         res++;
        //         return;
        //     }
        //     if (presentNum < 0){
        //         return;
        //     }
        //     for (int i : nums){
        //         // ����ܹ�����������ô�ͼ����ݹ飬����target
        //         // cout << i << endl;
        //         dfs(i, presentNum);
        //     }
        // };
        // dfs(0, target);
        // return res;
    }
};
