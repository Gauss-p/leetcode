#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        for (int l=1; l<=n; l++){
            for (int i=0; i<n-l+1; i++){
                int cur_or = 0;
                for (int j=i; j<i+l; j++){
                    cur_or = cur_or | nums[j];
                }
                if (cur_or >= k){
                    return l;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    int k = 2;
    cout << s.minimumSubarrayLength(nums, k) << endl;
}
