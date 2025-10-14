#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // 保存上一个连续递增段的长度和当前一个连续递增段的长度，每次记录两个连续递增段的最大值，即可得到最大可能的k值，同时需要判断一个连续段过长，可以分成两个递增段的情况，因此还需要取当前连续递增段的长度的一半来记录答案
        int n = nums.size();
        int last=0, cur=1, res = 0;
        for (int i=1; i<n; i++){
            if (nums[i] > nums[i-1]){
                cur++;
            }
            else{
                last = cur;
                cur = 1;
            }
            res = max(res, min(last, cur));
            res = max(res, cur/2);
        }
        return res>=k;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    cout << s.hasIncreasingSubarrays(nums, k) << endl;
}
