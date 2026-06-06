#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> lSum(n, 0), rSum(n, 0);
        for (int i=0; i<n-1; i++){
            lSum[i+1] = lSum[i]+nums[i];
            rSum[n-i-2] = rSum[n-i-1]+nums[n-i-1];
        }
        vector<int> res;
        for (int i=0; i<n; i++) res.push_back(abs(lSum[i]-rSum[i]));
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,4,8,3};
    vector<int> res = s.leftRightDifference(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
