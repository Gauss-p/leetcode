#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        unordered_map<int, int> length;
        int mx = 0, last = 0;
        for (int i=1; i<n; i++){
            if (nums[i] != nums[i-1]){
                length[nums[i-1]] = max(length[nums[i-1]], i-last);
                last = i;
            }
            mx = max(mx, nums[i-1]);
        }
        return length[mx];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,3,2,2};
    cout << s.longestSubarray(nums) << endl;
}
