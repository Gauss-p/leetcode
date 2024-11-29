#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        // 用动态规划的方法，定义dp[i][j]表示当arr1[i]=j时，前i+1位上填的数组对方案总数，所以，对于dp[i][v2]，我们只需考虑前一位上填的数字的所有可能即可，我们假设前一位即arr[i-1]填的是v1，那么v1需要满足以下条件：1.v1<=v2 2.nums[i-1]-v1>=nums[i]-v2。
        // 其中第一个条件是为了保证arr1的非递减性，第二个条件则是为了保证arr2的非递增性，同时我们还要保证arr1和arr2中所有数均为非负数，即需要保证nums[i]-v2>=0(因为nums[i-1]-v1已经比nums[i]-v2大了，所以我们就不用考虑nums[i-1]的问题)，最后，dp[i][v2]就是所有满足条件的v1对应的dp[i-1][v1]数值之和

        // 以上的方法在计算第一题的时候还可以过，但是第二题就面临超时的问题，这时候我们需要对其进行优化
        // 我们首先考虑上面的第二个条件，nums[i-1]-v1 >= nums[i]-v2，经过移项，可以得到v2 >= v1 + (nums[i]-nums[i-1])，我们定义d=max(0, nums[i]-nums[i-1])，用来表示v2的最小可能值，因为v2>=0，所以我们将nums[i]-nums[i-1]和0取一个最大值就可以保证非负性。
        // 接下来，根据第一个条件，v1<=v2，根据第二个条件，v1<=v2-d，那么v1最大应是v2-d，所以dp[i][v2]就应该是dp[i-1][0]+dp[i-1][1]+···+dp[i-1][v2-d-1]+dp[i-1][v2-d]，同理，当v2>0时，dp[i][v2-1]应该是dp[i-1][0]+dp[i-1][1]+···+dp[i-1][v2-d-1]，两者相比较，可以发现，当v2>0时，dp[i][v2] = dp[i][v2-1]+dp[i-1][v2-d]，否则dp[i][v2] = dp[i-1][v2-d]，这样就可以减少v1的循环
        // 在所有都计算完以后，答案就是dp[n-1]内所有数值之和
        int n = nums.size();
        int modNum = 1e9+7;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        // 题目保证nums中最大值为50，所以dp[i]的规模设置为51即可
        for (int j=0; j<=nums[0]; j++){
            // 对于dp[0]，因为它只代表一位，不存在增减性的问题，所以只要填nums[0]以内的数都可以
            dp[0][j] = 1;
        }
        for (int i=1; i<n; i++){
            int d = max(0, nums[i]-nums[i-1]);
            for (int v2=d; v2<=nums[i]; v2++){
                dp[i][v2] = dp[i-1][v2-d]; // 无论v2大于还是等于0，dp[i][v2]都有一项是dp[i-1][v2-d]
                if (v2 != 0){
                    // 但是只有在v2>0时，dp[i][v2]才有dp[i][v2-1]这个项
                    dp[i][v2] = (dp[i][v2]+dp[i][v2-1])%modNum;
                }
            }
        }
        // 统计答案
        int res = 0;
        for (int i : dp[n-1]){
            res = (res+i)%modNum;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {2,3,2};
    Solution s;
    cout << s.countOfPairs(nums) << endl;
}
