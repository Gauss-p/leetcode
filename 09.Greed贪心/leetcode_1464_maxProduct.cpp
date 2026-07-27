#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,4,5,2};
    cout << s.maxProduct(nums) << endl;
}
