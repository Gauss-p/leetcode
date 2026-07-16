#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> preGcd;
        int mx = 0;
        for (int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            preGcd.push_back(__gcd(mx, nums[i]));
        }
        sort(preGcd.begin(), preGcd.end());

        long long res = 0;
        for (int i=0; i<n/2; i++){
            res += __gcd(preGcd[i], preGcd[n-i-1]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,6,4};
    cout << s.gcdSum(nums) << endl;
}
