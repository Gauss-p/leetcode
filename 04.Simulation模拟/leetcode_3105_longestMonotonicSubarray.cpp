#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int up = 1, down = 1;
        int max_up = 1, max_down = 1;
        for (int i=1; i<n; i++){
            if (nums[i-1] >= nums[i]){
                max_up = max(max_up, up);
                up = 0;
            }
            up++;
        }
        max_up = max(max_up, up);
        for (int i=1; i<n; i++){
            if (nums[i-1] <= nums[i]){
                max_down = max(max_down, down);
                down = 0;
            }
            down++;
        }
        max_down = max(max_down, down);
        // cout << max_down << " " << max_up;
        return max(max_down, max_up);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,3,3,2};
    cout << s.longestMonotonicSubarray(nums) << endl;
}
