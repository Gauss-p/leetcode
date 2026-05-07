#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int indx = lower_bound(nums.begin(), nums.end(), k)-nums.begin();
        return indx;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    cout << s.minOperations(nums, k) << endl;
}
