#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        // 总的思路就是深度优先搜索，以每一个数字作为第一个元素向后搜索，然后将所有的可能累加到一起即可
        // 因为如果单独对第一个元素进行一次循环太复杂，所以直接将其融入dfs中
        // 每一次循环为访问的元素，如果满足规则，就直接进入下一次循环，直到将所有元素都访问一遍
        // 但是这样容易超时，所以进行优化
        // 第一种是利用位运算进行优化，每一个元素如果访问过，就将这个元素的索引indx取出
        // 取出后保存成一个二进制数(1<<indx)，也就是从左到右第i位是否为1就代表了是否访问过
        // 每一次传入时进行修改即可
        // 第二种方法是直接用存好的二进制数变成字符串，再将当前最后一个数字变成字符串，两个用‘-’连接
        // 拼接好的字符串作为键，计算好的答案作为值，存入字典memo中即可
        // 每次判断是否计算过，就可以节省时间
        int n = nums.size();
        int mod_num = 1e9+7;
        vector<vector<int>> memo(1<<n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int prevPos, int u){
            if (u == (1<<n)-1){
                return 1;
            }
            if (prevPos != -1 && memo[u][prevPos] != -1){
                return memo[u][prevPos];
            }
            int res = 0;
            for (int i=0; i<n; i++){
                if (((u >> i) & 1) == 0){
                    if (prevPos == -1 || nums[i]%nums[prevPos] == 0 || nums[prevPos]%nums[i] == 0){
                        res = (res+dfs(i, u|(1<<i)))%mod_num;
                    }
                }
            }
            if (prevPos != -1){
                memo[u][prevPos] = res%mod_num;
            }
            return res%mod_num;
        };
        return dfs(-1, 0);
        // 以下代码可以通过
        // int n = nums.size();
        // int mod_num = 1e9+7;
        // unordered_map<string, int> memo;
        // vector<int> visited(n, 0);
        // function<int(int, int, int)> dfs = [&](int depth, int prevPos, int u){
        //     if (depth == n){
        //         return 1;
        //     }
        //     string key = to_string(prevPos)+"-"+to_string(u);
        //     if (memo.count(key)){
        //         return memo[key];
        //     }
        //     int &res = memo[key];
        //     for (int i=0; i<n; i++){
        //         if (visited[i] == 0){
        //             if (prevPos == -1 || nums[i]%nums[prevPos]==0 || nums[prevPos]%nums[i] == 0){
        //                 visited[i] = 1;
        //                 res = (res+dfs(depth+1, i, u|(1<<i)))%mod_num;
        //                 visited[i] = 0;
        //             }
        //         }
        //     }
        //     return res;
        // };
        // return dfs(0, -1, 0)%mod_num;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 3, 6};
    cout << s.specialPerm(nums) << endl;
}
