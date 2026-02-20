#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int lastMin = INT_MAX;
        for (int i=0; i<n; i++){
            res = max(res, nums[i]-lastMin);
            lastMin = min(lastMin, nums[i]);
        }
        return res==0 ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {7,1,5,4};
    cout << s.maximumDifference(nums) << endl;
}
