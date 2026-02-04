#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long res = LLONG_MIN/2;
        long long f1 = LLONG_MIN/2, f2 = LLONG_MIN/2, f3 = LLONG_MIN/2;
        int n = nums.size();
        for (int i=0; i<n-1; i++){
            int x = nums[i], y = nums[i+1];
            f3 = x<y ? max(f2, f3)+y : LLONG_MIN/2;
            f2 = x>y ? max(f1, f2)+y : LLONG_MIN/2;
            f1 = x<y ? max(f1, 1ll*x)+y : LLONG_MIN/2;
            res = max(res, f3);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,-2,-1,-3,0,2,-1};
    cout << s.maxSumTrionic(nums) << endl;
}
