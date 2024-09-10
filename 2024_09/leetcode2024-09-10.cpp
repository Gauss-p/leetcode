#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        // 定义dp[j]表示以j为中间位置，类似132这样的三元组的数量
        // i从0到n开始遍历，同时将j从0到i遍历，每一次遍历的过程中，都可以保证i是在j后边的一个元素，所以，如果发现nums[i]比nums[j]大，就说明对于所有的以j为中心的"132"三元组如果加上i都可以组成一个上升四元组，那么这个时候就将答案加上dp[j]即可，同时统计以j为中心的三元组的数量cnt，之后只要发现一个比nums[j]小的元素dp[j]就可以加上cnt
        // 最终返回统计好的答案即可
        int n = nums.size();
        vector<long long> dp(n);
        long long res = 0;
        for (int i=0; i<n; i++){
            int cnt = 0;
            for (int j=0; j<i; j++){
                if (nums[i] > nums[j]){
                    // 确定四元组里的最后一个元素
                    res += dp[j];
                    // 确定三元组里的元素
                    cnt++;
                }
                else{
                    // 确定三元组的个数
                    dp[j] += cnt;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,4,5};
    cout << s.countQuadruplets(nums) << endl;
}
