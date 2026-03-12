#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;
        for (int i=0; i<=n-k; i++){
            res = min(res, nums[i+k-1]-nums[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {90};
    int k = 1;
    cout << s.minimumDifference(nums, k) << endl;
}
