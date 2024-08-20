#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int waysToReachStair(int k) {
        // 思路如下，用dfs遍历每一种情况，其中dfs(i, j, b)表示到达第i个台阶，同时jump为j，且上一次操作是否回退1个台阶时，能够到达第k级台阶的方案数
        // 可以发现，dfs(i, j, b)接下来的一步一定可以跳到i+2**j级台阶，但是同时也有可能往回退一个台阶，不过回退要满足两个条件，第一个是当前位于第1及以上的台阶，第二个是上一次并没有回退过，也就是b=false，最后将两种情况的方案数相加即可
        // 其中，只要i大于了k+1，就再也不可能跳回k，所以当i>k+1时就要返回。同时每一次i=k的时候就要将res+1
        unordered_map<long long, int> memo;
        auto dfs = [&](auto&& dfs, int i, int jump, bool back){
            int res = 0;
            if (i > k+1){
                return 0;
            }
            if (i == k){
                res = 1;
            }
            long long key = (long long)i<<32 | (long long)jump<<1 | back;
            if (memo.count(key)){
                return memo[key];
            }
            res += dfs(dfs, i+(1<<jump), jump+1, false);
            if (i >= 1 && back == false){
                res += dfs(dfs, i-1, jump, true);
            }
            memo[key] = res;
            return res;
        };
        return dfs(dfs, 1, 0, false);
    }
};

int main(){
    Solution s;
    int k = 100;
    cout << s.waysToReachStair(k) << endl;
}
