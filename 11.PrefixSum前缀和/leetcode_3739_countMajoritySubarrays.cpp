#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+(nums[i]==target);
        }

        vector<int> stl;
        long long res = 0;
        for (int i=0; i<n; i++){
            int indx0 = upper_bound(stl.begin(), stl.end(), 2*preSum[i]-i)-stl.begin();
            stl.insert(stl.begin()+indx0, 2*preSum[i]-i);
            int cur = 2*preSum[i+1]-(i+1);
            int indx = lower_bound(stl.begin(), stl.end(), cur)-stl.begin();
            res += indx;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,3};
    int target = 2;
    cout << s.countMajoritySubarrays(nums, target) << endl;
}
