#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int totGcd = 0, ones = 0;
        for (int i : nums){
            ones += (i==1);
            totGcd = __gcd(totGcd, i);
        }
        if (totGcd != 1){
            return -1;
        }

        int n = nums.size();
        if (ones > 0){
            return n-ones;
        }

        int minLength = INT_MAX;
        for (int i=0; i<n; i++){
            int curGcd = nums[i];
            for (int j=i+1; j<n; j++){
                curGcd = __gcd(curGcd, nums[j]);
                if (curGcd == 1){
                    minLength = min(minLength, j-i+1);
                    break;
                }
            }
        }
        return minLength-1+n-1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,6,3,4};
    cout << s.minOperations(nums) << endl;
}
