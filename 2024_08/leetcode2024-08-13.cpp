#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; i++){
            if (nums[i]%2 == nums[i+1]%2){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.isArraySpecial(nums) << endl;
}
