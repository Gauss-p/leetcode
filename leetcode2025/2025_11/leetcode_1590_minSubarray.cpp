#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> preSum(n+1, 0);
        int target = 0;
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+nums[i];
            target = (target+nums[i])%p;
        }
        if (target == 0){
            return 0;
        }

        // 自定义哈希表中的默认值
        struct init{
            int num = INT_MIN/2;
        };
        unordered_map<int, init> mp;
        int res = INT_MAX;
        for (int i=0; i<=n; i++){
            int curRound = preSum[i]%p;
            mp[curRound].num = i;
            int lastRound = (curRound-target + p)%p;
            int last = mp[lastRound].num;

            if (i-last < res){
                res = i-last;
            }
        }
        return res==n ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,4,2};
    int p = 6;
    cout << s.minSubarray(nums, p) << endl;
}
