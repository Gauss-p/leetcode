#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int last = 0, cur = 1, res = 0;
        for (int i=1; i<n; i++){
            if (nums[i-1] < nums[i]){
                cur++;
            }
            else{
                last = cur;
                cur = 1;
            }
            res = max(res, min(last, cur));
            res = max(res, cur/2);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    cout << s.maxIncreasingSubarrays(nums) << endl;
}
