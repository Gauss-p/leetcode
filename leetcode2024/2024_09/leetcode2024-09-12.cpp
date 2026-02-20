#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        // 首先将整个数组排序，分成大的和小的两部分，用si表示小的一部分数组中的索引，用bi表示大的一部分中的索引
        // 接下来，循环bi，如果nums[si]和nums[bi]可以满足nums[si]*2<=nums[bi]，那么我们就可以将si右移一位，同时标记两个数字，如果说无法满足，那么因为已经排序，所以ai之后的小的一部分中所有数字都不可能和bi配对，所以说将bi向右移动会更加合适
        sort(nums.begin(), nums.end());
        int si = 0, n = nums.size();
        int res = 0;
        for (int bi=(n+1)/2; bi<n; bi++){
            if (nums[si]*2 <= nums[bi]){
                res += 2;
                si++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {3,5,2,4};
    Solution s;
    cout << s.maxNumOfMarkedIndices(nums) << endl;
}
