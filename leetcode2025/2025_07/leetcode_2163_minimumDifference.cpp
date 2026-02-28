#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/3;
        vector<long long> preMin(m+1, LLONG_MAX);
        priority_queue<long long> curNums;
        long long curSum = 0;
        for (int i=0; i<n; i++){
            curSum += nums[i];
            curNums.push(nums[i]);
        }
        preMin[n] = curSum;
        for (int i=n; i<m; i++){
            curSum += nums[i];
            curNums.push(nums[i]);
            curSum -= curNums.top();
            curNums.pop();
            preMin[i+1] = min(preMin[i], curSum);
        }

        vector<long long> sufMax(m+1, 0);
        priority_queue<long long> sufNums;
        curSum = 0;
        for (int i=2*n; i<m; i++){
            curSum += nums[i];
            sufNums.push(-nums[i]);
        }
        sufMax[2*n] = curSum;
        for (int i=2*n-1; i>=0; i--){
            curSum += nums[i];
            sufNums.push(-nums[i]);
            curSum -= (-sufNums.top());
            sufNums.pop();
            sufMax[i] = max(sufMax[i+1], curSum);
        }

        long long res = LLONG_MAX;
        for (int i=n; i<=2*n; i++){
            res = min(res, preMin[i]-sufMax[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {7,9,5,8,1,3};
    cout << s.minimumDifference(nums) << endl;
}
