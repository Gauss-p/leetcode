// 2848. 与车相交的点
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // 差分数组法，我们如果对原数组中每一辆车所覆盖的点都加1，太过麻烦，所以用差分数组的方法，直接对每一辆车的begin位置加1，然后对每一辆车的end+1位置减1，就可以相当于在原数组实现从begin到end都加1，最后还原成原数组，对标记次数大于0的点都统计就可以了
        int n = nums.size();
        vector<int> d(102, 0);
        for (int i=0; i<n; i++){
            // 加入一辆车
            d[nums[i][0]]++;
            d[nums[i][1]+1]--;
        }
        int res = 0, tmp = 0;
        for (int i : d){
            // 还原成原数组
            tmp += i;
            if (tmp > 0){
                res++;
            }
        }
        return res;
        // 合并区间法
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int bg = nums[0][0], ed = nums[0][1];
        // int res = 0;
        // for (int i=1; i<n; i++){
        //     if (nums[i][0] <= ed){
        //         ed = max(ed, nums[i][1]);
        //     }
        //     else{
        //         res += ed-bg+1;
        //         bg = nums[i][0];
        //         ed = nums[i][1];
        //     }
        // }
        // res += ed-bg+1;
        // return res;
    }
};

int main(){
    vector<vector<int>> nums = {{3,6},{1,5},{4,7}};
    Solution s;
    cout << s.numberOfPoints(nums) << endl;
}
