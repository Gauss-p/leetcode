#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int preSum = 0, totSum = 0;
        for (auto& i : nums) totSum += i;
        int res = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                if (preSum*2 == totSum){
                    res += 2;
                }
                if (abs(preSum*2-totSum) == 1){
                    res += 1;
                }
            }
            preSum += nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,0,2,0,3};
    cout << s.countValidSelections(nums) << endl;
}
