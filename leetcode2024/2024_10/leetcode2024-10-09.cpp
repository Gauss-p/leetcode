#include <iostream>
#include <functional>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // 用arr存储每一位上1的个数，这样就可以方便不定长滑动窗口的进数字和出数字，这时我们需要两个函数，分别用来滑动窗口的删除和添加数字，以及当前窗口内所有数字相或的值。因为删除和添加数字只不过一个是减1，一个是加1，所以我们可以将+1和-1整合成一个参数delta传入即可，而函数的内部直接对需要操作的数字tmp中每一个有1的位对应的arr内的数字加上delta即可。而对于第二个函数，我们要计算窗口内所有值相或，所以直接将arr中每一个大于0的位置累加位权即可
        if (nums.size() == 1){
            return abs(nums[0]-k);
        }
        vector<int> numPositions(32, 0);
        auto addNum = [&](int tmp, int delta){
            // 加入/删除数字
            for (int i=0; i<32; i++){
                if (((tmp >> i)&1) == 1){
                    numPositions[i] += delta;
                }
            }
        };
        auto calOrValue = [&](){
            // 计算当前窗口内的所有数字相或的值
            int res = 0;
            for (int i=0; i<32; i++){
                if (numPositions[i]){
                    res += (1<<i);
                }
            }
            return res;
        };
        int n = nums.size();
        int l = 0, r = 0;
        int ans = INT_MAX;
        int cur = 0;
        for (; l<n; l++){
            while (r<n && cur<k){
                // 不断向后滑动，直到发现当前窗口内所有元素相或的值大于等于k就退出
                cur |= nums[r];
                ans = min(ans, abs(cur-k)); // 记录答案
                addNum(nums[r], 1);
                r++;
            }
            ans = min(ans, abs(cur-k));
            if (cur == k){
                // 如果当前窗口内按位或的值正好为k，直接返回0即可
                return 0;
            }
            if (cur > k){
                // 否则，向前回退一个数字，再次计算最小值
                addNum(nums[l], -1);
                cur = calOrValue();
                if (cur > 0){
                    ans = min(ans, abs(cur-k));
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {42,49,95,76,66};
    int k = 12;
    cout << s.minimumDifference(nums, k) << endl;
}
