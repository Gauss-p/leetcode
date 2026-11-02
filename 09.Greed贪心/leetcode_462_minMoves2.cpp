#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2];
        int res = 0;
        for (int i : nums){
            res += abs(i-mid);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.minMoves2(nums) << endl;
}
