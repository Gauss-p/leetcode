#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0]==0 ? 1 : 2; // 考虑两种情况，因为题目数据保证了至少有一种方案是全部选择，所以第一种情况：全选，是一定有的，第二种情况是全不选，这需要在全数组中最小值大于0时才可以
        for (int i=0; i<n-1; i++){
            if (i+1 > nums[i] && i+1 < nums[i+1]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1};
    cout << s.countWays(nums) << endl;
}
