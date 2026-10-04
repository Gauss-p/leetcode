#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n+1, 0), aft(n+1, 0);
        for (int i=0; i<n; i++){
            pre[i+1] = pre[i]|nums[i];
            aft[n-i-1] = aft[n-i]|nums[n-i-1];
        }
        long long res = 0;
        for (int i=0; i<n; i++){
            long long tmp = pre[i]|aft[i+1]|(1ll*nums[i]<<k);
            res = max(res, tmp);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {12,9};
    int k = 1;
    cout << s.maximumOr(nums, k) << endl;
}
