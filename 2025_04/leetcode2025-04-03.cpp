#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n+1, 0), aft(n+1, 0);
        for (int i=0; i<n; i++){
            pre[i+1] = max(pre[i], 1ll*nums[i]);
            aft[n-i-1] = max(aft[n-i], 1ll*nums[n-i-1]);
        }
        long long res = 0;
        for (int i=0; i<n; i++){
            res = max(res, 1ll*(pre[i]-nums[i])*aft[i+1]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {12,6,1,2,7};
    cout << s.maximumTripletValue(nums) << endl;
}
