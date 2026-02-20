#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double res = 1000000;
        for (int i=0; i<n/2; i++){
            double tmp = (nums[i]+nums[n-i-1])/2.0;
            res = min(res, tmp);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {7,8,3,4,15,13,4,1};
    Solution s;
    cout << s.minimumAverage(nums) << endl;
}
