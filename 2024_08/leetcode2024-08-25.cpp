#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0, mx = 0;
        for (int i : nums){
            total += i;
            mx = max(mx, i);
        }
        int n = nums.size();
        if (total % k != 0){
            return false;
        }
        if (mx > total/k){
            return false;
        }
        int success = total/k;
        sort(nums.rbegin(), nums.rend());
        vector<int> tmp(k, success);
        auto dfs = [&](auto&& dfs, int indx){
            // 这种思路是循环数字，将数字装到桶里，只要能够装进去一个数字，就直接循环下一个数字，直到全部装完，就说明答案就是true，否则，如果每一种情况都不行，就返回false
            if (indx >= n) return true;
            for (int i=0; i<k; i++){
                if (nums[indx] > tmp[i]) continue;
                if (i > 0 && tmp[i] == tmp[i-1]){
		    // 这一句的意义在于，如果当前循环到的桶和前一个桶的容量一样，而该数字又没有放在前一个桶里，就说明该数字不能放在当前桶中
                    continue;
                }
                tmp[i] -= nums[indx];
                if (dfs(dfs, indx+1)) return true;
                tmp[i] += nums[indx];
            }
            return false;
        };
        return dfs(dfs, 0);
        // ----------------------------------
        // int total = 0, mx = 0;
        // for (int i : nums){
        //     total += i;
        //     mx = max(mx, i);
        // }
        // int n = nums.size();
        // if (total % k != 0){
        //     return false;
        // }
        // if (mx > total/k){
        //     return false;
        // }
        // int success = total/k;
        // sort(nums.begin(), nums.end(), greater<int>());
        // vector<int> tmp(k, 0);
        // vector<int> visited(n, 0);
        // auto dfs = [&](auto&& dfs, int indx){
        //     if (indx == k){
        //         return true;
        //     }
        //     if (tmp[indx] == success){
        //         return dfs(dfs, indx+1);
        //     }
        //     for (int i=0; i<n; i++){
        //         if (visited[i] == 0){
        //             if (tmp[indx]+nums[i] > success){
        //                 continue;
        //             }
        //             visited[i] = 1;
        //             tmp[indx] += nums[i];
        //             if (dfs(dfs, indx)){
        //                 return true;
        //             }
        //             tmp[indx] -= nums[i];
        //             visited[i] = 0;
        //         }
        //     }
        //     return false;
        // };
        // return dfs(dfs, 0);
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;
    cout << s.canPartitionKSubsets(nums, k) << endl;
}
