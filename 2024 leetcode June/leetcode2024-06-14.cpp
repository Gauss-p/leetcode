#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        vector<long long> dp(2, INT_MIN); // dp[0]用来表示偶数的最大值，1用来表示奇数的最大值
        int n = nums.size();
        dp[nums[0]%2] = nums[0];
        long long res = nums[0];
        for (int i=1; i<n; i++){
            int p = nums[i]%2;
            // 求两种情况的最大值，再与之前对比，求最大
            long long cur = max(dp[p]+nums[i], dp[1-p]+nums[i]-x);
            res = max(cur, res);
            dp[p] = max(dp[p], cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,6,1,9,2};
    int x = 5;
    cout << s.maxScore(nums, x) << endl;
}
