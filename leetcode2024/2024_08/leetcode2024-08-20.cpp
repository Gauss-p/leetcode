#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    string res;
    vector<vector<int>> visited;
    vector<int> p;
    int m;
    int my_n;
    int my_k;
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
    // the next problem:The Largest Palindrome
    bool dfs(int i, int j){
        if (i == m){
            return j==0;
        }
        visited[i][j] = 1;
        for (int d=9; d>=0; d--){
            int j2 = (j+d*(p[i]+p[my_n-i-1]))%my_k;
            if (my_n%2 == 1 && i == m-1){
                j2 = (j+d*p[i])%my_k;
            }
            if (visited[i+1][j2]==0 && dfs(i+1, j2)){
                res[i] = res[my_n-i-1] = '0'+d;
                return true;
            }
        }
        return false;
    };
    string largestPalindrome(int n, int k) {
        // 这道题目思路如下，首先通过找规律可以发现，10^n抹除k的值等于10^(n-1)抹除k的值乘以10再抹除k，通过这个规律，可以得出n位上各个位抹除k以后得到多少，通过这个，我们就可以更好地判断一个数是否被k整除
        // 接下来定义dfs，其中dfs(i,j)表示要在第i位上填写数字，且之前填的所有数字抹除k的答案是j，那么因为要答案最大，所以我们可以直接从大到小循环每一个可以填入的数字，然后传入下一次计算，只要发现有一种方案可行，就返回true,同时开始记录答案，从大到小，第一个合法数字就是最大的合法数字
        my_n = n;
        my_k = k;
        p.resize(n, 1);
        for (int i=1; i<n; i++){
            p[i] = (p[i-1]*10)%k;
        }
        m = (n+1)/2;
        visited.resize(m+1, vector<int>(k, 0));
        res.resize(n, 0);

        dfs(0, 0);
        return res;
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        long long sum = 0;
        for (int i=0; i<n; i++){
            sum += nums[i];
            if (i < 2*k){
                continue;
            }
            res[i-k] = sum/(2*k+1);
            sum -= nums[i-2*k];
        }
        return res;
    }
};

int main(){
    Solution s;
    int k = 100;
    cout << s.waysToReachStair(k) << endl;
    int n = 3, k2 = 5;
    cout << s.largestPalindrome(n, k2) << endl;
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k3 = 3;
    vector<int> res = s.getAverages(nums, k3);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
