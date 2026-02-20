#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());
        return res+nums[0]+nums[1];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,12};
    cout << s.minimumCost(nums) << endl;
}
