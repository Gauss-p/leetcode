#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;
    int n, modNum;
    vector<int> NUMS;

    int dfs(int indx, int g1, int g2){
        if (indx == n){
            if (g1 == g2){
                return 1;
            }
            return 0;
        }
        int key = (indx<<16) | (g1<<8) | g2;
        if (memo.count(key)){
            return memo[key];
        }
        return memo[key] = (1ll*dfs(indx+1, __gcd(g1, NUMS[indx]), g2)+
               1ll*dfs(indx+1, g1, __gcd(g2, NUMS[indx]))+
               1ll*dfs(indx+1, g1, g2))%modNum;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        modNum = 1e9+7;
        n = nums.size();
        NUMS = nums;
        return dfs(0, 0, 0)-1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.subsequencePairCount(nums) << endl;
}
