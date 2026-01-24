#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        for (int i=0; i<n/2; i++){
            res = max(res, nums[i]+nums[n-i-1]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,5,2,3};
    cout << s.minPairSum(nums) << endl;
}
