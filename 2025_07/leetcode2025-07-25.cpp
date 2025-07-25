#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, last = INT_MAX;
        for (int& i : nums){
            if (i > 0 && i != last){
                res += i;
                last = i;
            }
        }
        return nums.back()<0 ? nums.back() : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    cout << s.maxSum(nums) << endl;
}
