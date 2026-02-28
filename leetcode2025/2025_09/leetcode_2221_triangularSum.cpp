#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; i++){
            for (int j=0; j<(n-i)-1; j++){
                nums[j] = (nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    cout << s.triangularSum(nums) << endl;
}
