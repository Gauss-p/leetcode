#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        // 利用滑动窗口，用字典统计各个数字出现次数，定义检查函数check，传入一个目标值t，t代表子数组中不同元素的最多数量，用滑动窗口计算每一个子数组的不同元素数量。循环子数组右端点，只要发现不同元素数量超出目标值t，就向右移动左端点，直到计算完。如果总数大于中位数前面的数字个数，就返回true，否则false
        // 在主函数中，用二分查找，定义左端点left和右端点right，每一次取中间值mid，用mid当作check函数中的目标值t进行检验，如果超过mid_num，就说明目标值还可以再小，right=mid-1，否则就右移左端点，left=mid+1
        int n = nums.size();
        long long mid_num = (1ll*n*(n+1)/2+1)/2;
        auto check = [&](int t){
            long long cnt = 0;
            unordered_map<int, int> mp;
            for (int l=0, r=0; r<n; r++){
                mp[nums[r]]++;
                while (mp.size()>t){
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0){
                        mp.erase(nums[l]);
                    }
                    l++;
                }
                cnt += r-l+1;
            }
            return cnt >= mid_num;
        };
        int res = 0;
        int left=1, right=n;
        while (left <= right){
            int mid = (left+right)/2;
            if (check(mid)){
                res = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.medianOfUniquenessArray(nums) << endl;
}
