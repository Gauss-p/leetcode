#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for (auto& i : nums){
            tot += i;
        }
        int preSum = 0;
        int res = 0;
        for (int i=0; i<n-1; i++){
            preSum += nums[i];
            if ((2*preSum-tot)%2 == 0){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,10,3,7,6};
    cout << s.countPartitions(nums) << endl;
}
