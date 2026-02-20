#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // 滑动窗口，自动循环右端点，只要发现左端点和右端点对应的数字之差大于k就将答案累加1，并将左端点置为当前右端点重新开始计算新的一个子数组
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int res = 1;
        for (int right=0; right<n; right++){
            if (nums[left]+k < nums[right]){
                res += 1;
                left = right;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,6,1,2,5};
    int k = 2;
    cout << s.partitionArray(nums, k) << endl;
}
