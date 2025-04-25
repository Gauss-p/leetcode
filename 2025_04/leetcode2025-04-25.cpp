#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+(nums[i]%modulo==k);
        }

        long long res = 0;
        unordered_map<int, int> cnt;
        for (int i=0; i<=n; i++){
            res += cnt[(preSum[i]-k)%modulo];
            cnt[preSum[i]%modulo]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,4};
    int modulo = 2;
    int k = 1;
    cout << s.countInterestingSubarrays(nums, modulo, k) << endl;
}
