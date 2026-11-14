#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int length = l;
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+nums[i];
        }
        int res = INT_MAX;
        for (;length <= r; length++){
            for (int i=0; i<=n-length; i++){
                int left = i, right = i+length;
                int tmpSum = preSum[right]-preSum[left];
                if (tmpSum > 0){
                    res = min(res, tmpSum);
                }
            }
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, -2, 1, 4};
    int l = 2;
    int r = 3;
    cout << s.minimumSumSubarray(nums, l, r) << endl;
}
