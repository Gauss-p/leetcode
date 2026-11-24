#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int prod = 1;
        int res = 2;
        for (int r=0; r<n; r++){
            while (__gcd(nums[r], prod) != 1){
                prod /= nums[l];
                l++;
            }
            res = max(res, r-l+1);
            prod *= nums[r];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
    cout << s.maxLength(nums) << endl;
}
