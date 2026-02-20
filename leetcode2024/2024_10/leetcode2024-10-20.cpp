#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx = 0, mn = INT_MAX;
        for (auto i : nums){
            mx = max(mx, i);
            mn = min(mn, i);
        }
        return max(mx-mn-2*k, 0);
    }
};

int main(){
    vector<int> nums = {1,3,6};
    int k = 3;
    Solution s;
    cout << s.smallestRangeI(nums, k) << endl;
}
