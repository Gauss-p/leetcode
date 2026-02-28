#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+nums[i];
        }

        vector<long long> leftSum(k, INT_MAX);
        long long res = LLONG_MIN;
        for (int i=0; i<=n; i++){
            int cur = i%k;
            if (leftSum[cur] != INT_MAX){
                res = max(res, preSum[i]-leftSum[cur]);
            }
            leftSum[cur] = min(leftSum[cur], preSum[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2};
    int k = 1;
    cout << s.maxSubarraySum(nums, k) << endl;
}
