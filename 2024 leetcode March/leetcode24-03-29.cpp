#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), left_min = nums[0], res = INT_MAX;
        for (int i=1; i<n-1; i++){
            int right_min = nums[i+1];
            for (int j=i+2; j<n; j++){
                right_min = min(right_min, nums[j]);
            }
            if (left_min < nums[i] && nums[i] > right_min){
                res = min(res, nums[i]+left_min+right_min);
            }
            left_min = min(left_min, nums[i]);
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,6,1,5,3};
    cout << s.minimumSum(nums) << endl;
}
