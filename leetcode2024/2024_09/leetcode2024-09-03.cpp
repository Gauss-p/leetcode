#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long mx = nums[0], mn = nums[0];
        for (int i=1; i<nums.size(); i++){
            long long x = nums[i];
            long long tmp_mn = mn;
            mn = min({mn, x, mx*x, mn*x}); // 最小值的计算与最大值同理
            mx = max({mx, x, mx*x, tmp_mn*x}); // 如果当前数字为正，最大乘积就是当前数字乘以之前最大乘积，如果当前数字为负，最大乘积就是当前值乘以之前最小值，当然也可以直接从当前数字开始
        }
        return mx;
        //---------------------------------------------------------------------
        // long long prod = 1;
        // int neg_num = 0, max_neg = INT_MIN, pos_num = 0, zero_num = 0;
        // for (int i : nums){
        //     if (i > 0){
        //         prod *= i; // 非零数字的乘积
        //         pos_num++; // 正数的个数
        //     }
        //     if (i == 0){
        //         zero_num++; // 0的个数
        //     }
        //     if (i < 0){
        //         prod *= i;
        //         neg_num++; // 负数的个数
        //         max_neg = max(max_neg, i); // 最大负数是哪个
        //     }
        // }
        // if (pos_num == 0 && neg_num == 1 && zero_num == 0){
        //     return prod;
        // }
        // if (pos_num == 0 && neg_num <= 1 && zero_num > 0){
        //     return 0;
        // }
        // if (pos_num == 0 && neg_num > 1){
        //     if (neg_num%2 == 0){
        //         return prod;
        //     }
        //     else{
        //         return prod/max_neg;
        //     }
        // }
        // if (pos_num > 0 && neg_num%2 == 0){
        //     return prod;
        // }
        // return prod/max_neg;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,-1,-5,2,5,-9};
    cout << s.maxStrength(nums) << endl;
}
