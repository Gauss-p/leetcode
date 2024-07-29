#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // int l = 0;
        // int res = 0;
        // for (int r=0; r<n; r++){
        //     while (nums[r]-nums[l] > 2*k){
        //         l++;
        //     }
        //     res = max(res, r-l+1);
        // }
        // return res;
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=nums[i]-k; j<=nums[i]+k; j+=max(k, 1)){
                int low = j-k, up = j+k;
                auto low_it = lower_bound(nums.begin(), nums.end(), low);
                auto up_it = lower_bound(nums.begin(), nums.end(), up+1);
                up_it = prev(up_it);
                int low_indx = low_it - nums.begin(), up_indx = up_it - nums.begin();
                res = max(res, up_indx-low_indx+1);
            }
            // int low = nums[i]-2*k, up = nums[i]+2*k;
            // auto low_it = lower_bound(nums.begin(), nums.end(), low);
            // auto up_it = lower_bound(nums.begin(), nums.end(), up+1);
            // up_it = prev(up_it);
            // int low_indx = low_it - nums.begin(), up_indx = up_it - nums.begin();
            // res = max(res, up_indx-low_indx+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4, 2, 1, 6};
    int k = 2;
    cout << s.maximumBeauty(nums, k) << endl;
}
