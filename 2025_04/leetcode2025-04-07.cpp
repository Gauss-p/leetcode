#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> N;
    unordered_map<long long, bool> memo;
    bool dfs(int i, int s){
        if (i < 0){
            return s == 0;
        }
        if (s < 0){
            return false;
        }
        long long key = (long long)i<<32 | (long long)s;
        if (memo.count(key)){
            return memo[key];
        }
        bool res = dfs(i-1, s-N[i])||dfs(i-1, s);
        memo[key] = res;
        return res;
    }
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for (int i : nums){
            tot += i;
        }
        if (tot&1){
            return false;
        }
        tot /= 2;
        N = nums;
        int n = nums.size();
        return dfs(n-1, tot);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout << s.canPartition(nums) << endl;
}
