#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int res = 0;
        for (int x : nums){
            dp[x+1] = max(dp[x+1], dp[x]+1);
            dp[x] = max(dp[x], dp[x-1]+1);
            res = max(res, max(dp[x+1], dp[x]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,5,1,1};
    cout << s.maxSelectedElements(nums) << endl;
}
