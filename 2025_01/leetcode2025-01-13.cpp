#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot = 0;
        for (int i : nums){
            tot += i;
        }
        long long pre = 0, res = 0;
        for (int i=0; i<nums.size()-1; i++){
            pre += nums[i];
            if (2*pre >= tot){
                res++;
            }
        }
        return res;
    }
}; 

int main(){
    Solution s;
    vector<int> nums = {2,3,1,0};
    cout << s.waysToSplitArray(nums) << endl;
}
