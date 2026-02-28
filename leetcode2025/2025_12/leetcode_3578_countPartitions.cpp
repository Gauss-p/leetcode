#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int modNum = 1e9+7;
        deque<int> minQueue, maxQueue;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int preSum = 0;
        int left = 0;

        for (int i=0; i<n; i++){
            preSum = (preSum+dp[i])%modNum;
            int v = nums[i];
            while (!minQueue.empty() && v <= nums[minQueue.back()]){
                minQueue.pop_back();
            }
            minQueue.push_back(i);

            while (!maxQueue.empty() && v >= nums[maxQueue.back()]){
                maxQueue.pop_back();
            }
            maxQueue.push_back(i);

            while (nums[maxQueue.front()]-nums[minQueue.front()] > k){
                preSum = ((preSum-dp[left])%modNum + modNum)%modNum;
                left++;
                if (maxQueue.front() < left){
                    maxQueue.pop_front();
                }
                if (minQueue.front() < left){
                    minQueue.pop_front();
                }
            }

            dp[i+1] = preSum;
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    vector<int> nums = {9,4,1,3,7};
    int k = 4;
    cout << s.countPartitions(nums, k) << endl;
}
