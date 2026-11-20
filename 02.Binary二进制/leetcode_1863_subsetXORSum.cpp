#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i : nums){
            res |= i;
        }
        return res<<(n-1);
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,1,6};
    cout << s.subsetXORSum(nums) << endl;
}
