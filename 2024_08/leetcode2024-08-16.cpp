#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int INF;
    int n;
    int m;
    unordered_map<long long, int> mp;
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        // 对于这道题目，思路是这样的，定义dfs(i,j,and_Val)表示当前要分的第j段到第i个元素为止，并且其中的按位and值是and_Val，在这样的情况下子数组值之和
        // 那么我们可以发现，对于每一个元素i有两种情况，第一种是将其归入当前子数组，第二种是将其归入下一个子数组，如果是第一种情况，那么res就是dfs(i+1, j, and_Val&nums[i])，而第二种情况的前提条件是在将当前元素进行按位and运算后，该子数组的and结果和andValues[j]相等，这时候，因为以nums[i]结尾，所以答案就是dfs(i+1, j+1, -1)+nums[i]其中最后一个是-1是因为-1的二进制全部都是1。又因为我们求的是最小值，所以可以得出以下公式：
        // 如果and_Val&nums[i]!=andValues[j]，那么res = dfs(i+1, j, and_Val&nums[i])
        // 否则，res = min(dfs(i+1, j, and_Val&nums[i]), dfs(i+1, j+1, -1)+nums[i])
        // 同时，我们还要注意递归基，如果当前传入的i和j无法满足nums中剩下的数正好配andValues剩下的所有值，也就是如果n-i<m-j(n = nums.size(), m = andValues.size())，那么无法完成配对，返回INF
        // 另外一种情况是，如果j已经达到最后一个值，那么如果i达到了最后一个数字，就返回0，否则返回INF
        // Notice : 在编码的过程中，要注意dfs函数的定义和速度有关，auto dfs = [&](auto&& dfs)比function<> dfs = [&]()要快，如果不想要区分，就直接定义在主函数外面即可
        INF = INT_MAX/2;
        n = nums.size();
        m = andValues.size();
        // unordered_map<long long, int> mp;
        // auto dfs = [&](auto&& dfs, int i, int j, int and_Val){
        
        int ans = dfs(0, 0, -1, nums, andValues);
        if (ans < INF){
            return ans;
        }
        return -1;
    }

    int dfs(int i, int j, int and_Val, vector<int>& nums, vector<int>& andValues){
        // int n = nums.size(), m = andValues.size();
        if (n-i < m-j){
            return INF;
        }
        if (j == m){
            if (i == n){
                return 0;
            }
            else{
                return INF;
            }
        }
        and_Val &= nums[i];
        // string key = to_string(i)+"-"+to_string(j)+"-"+to_string(and_Val);
        long long key = (long long) i<<36 | (long long) j<<32 | and_Val;
        if (mp.count(key)){
            return mp[key];
        }
        int res = dfs(i+1, j, and_Val, nums, andValues);
        if (and_Val == andValues[j]){
            res = min(res, dfs(i+1, j+1, -1, nums, andValues)+nums[i]);
        }
        mp[key] = res;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,3,3,2};
    vector<int> andValues = {0,3,3,2};
    cout << s.minimumValueSum(nums, andValues) << endl;
}
