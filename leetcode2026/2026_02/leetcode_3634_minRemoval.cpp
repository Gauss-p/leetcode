#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = 0;
        int res = n-1;
        for (int l=0; l<n; l++){
            while (r<n && 1ll*nums[r] <= 1ll*nums[l]*k){
                r++;
            }
            res = min(res, n-(r-l));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,5};
    int k = 2;
    cout << s.minRemoval(nums, k) << endl;
}
