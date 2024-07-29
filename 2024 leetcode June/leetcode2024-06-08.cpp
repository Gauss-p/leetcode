#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        bool ok = false;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int, int)> dfs = [&](int i, int j, int t){
            if (ok == true) return 0;
            if (i >= j){
                ok = true;
                return 0;
            }
            int& res = memo[i][j];
            if (res != -1) return res;
            res = 0;
            if (nums[i]+nums[i+1] == t){
                // 删除前两个，求最大次数
                res = max(res, dfs(i+2, j, t)+1);
            }
            if (nums[i]+nums[j] == t){
                // 删除第一个和最后一个，求最大次数
                res = max(res, dfs(i+1, j-1, t)+1);
            }
            if (nums[j-1]+nums[j] == t){
                // 删除最后两个，求最大次数
                res = max(res, dfs(i, j-2, t)+1);
            }
            return res;
        };
        int ans = 0;
        ans = max(ans, dfs(2, n-1, nums[0]+nums[1]));
        ok = false;
        memo.resize(n, vector<int>(n, -1));
        ans = max(ans, dfs(1, n-2, nums[0]+nums[n-1]));
        ok = false;
        memo.resize(n, vector<int>(n, -1));
        ans = max(ans, dfs(0, n-3, nums[n-2]+nums[n-1]));
        return ans+1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,2,1,2,1};
    cout << s.maxOperations(nums) << endl;
}
