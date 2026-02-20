#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i=0; i<n-2; i++){
            if ((nums[i]+nums[i+2])*2 == nums[i+1]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,4,1};
    cout << s.countSubarrays(nums) << endl;
}
