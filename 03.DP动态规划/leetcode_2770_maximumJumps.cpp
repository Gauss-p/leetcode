#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[n-1] = 0;
        for (int i=n-2; i>=0; i--){
            for (int j=i+1; j<n; j++){
                if (abs(nums[i]-nums[j]) <= target){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp[0] > 0 ? dp[0] : -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,6,4,1,2};
    int target = 2;
    cout << s.maximumJumps(nums, target) << endl;
}
