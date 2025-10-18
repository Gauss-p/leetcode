#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums[0] -= k;
        int res = 1;
        for (int i=1; i<nums.size(); i++){
            nums[i] = min(max(nums[i-1]+1, nums[i]-k), nums[i]+k);
            if (nums[i] != nums[i-1]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,3,3,4};
    int k = 2;
    cout << s.maxDistinctElements(nums, k) << endl;
}
