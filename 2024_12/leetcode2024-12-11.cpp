#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int mn = 0, mx = 0, n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i] == 1){
                mn = i;
            }
            if (nums[i] == n){
                mx = i;
            }
        }
        int res = mn+(n-mx-1);
        if (mx < mn){
            res--;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,4,1,3};
    cout << s.semiOrderedPermutation(nums) << endl;
}
