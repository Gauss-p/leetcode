#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 滑动窗口，确定最大值，求最小值，并计算此时可以保留的数字数量，求最大，用原长度减即可
        int left = 0, right = 0; // 左右边界
        // 接下来是去重操作，是为了满足题目要求
        set<int> s(nums.begin(), nums.end());
        vector<int> n_nums(s.begin(), s.end());
        // 对原数组进行排序，求左端点就更容易
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = n_nums.size();
        int res = 0;
        for (int i=0; i<m; i++){
            right = i;
            int except_left = n_nums[i]-n+1; // 期望的左端点值
            while (n_nums[left] < except_left){
                // 该循环用来求左端点的索引
                left++;
            }
            // 能留下的元素越多，需要删除的元素越少
            res = max(res, right-left+1);
        }
        return n-res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,5,3};
    cout << s.minOperations(nums) << endl;
}
