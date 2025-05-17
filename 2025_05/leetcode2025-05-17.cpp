#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0=0, n1=0, n2=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                nums[n2++] = 2;
                nums[n1++] = 1;
                nums[n0++] = 0;
                // n0 += 1;
                // n1 += 1;
                // n2 += 1;
            }
            else if (nums[i] == 1){
                nums[n2++] = 2;
                nums[n1++] = 1;
                // n1 += 1;
                // n2 += 1;
            }
            else{
                nums[n2++] = 2;
                // n2 += 1;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for (int i : nums){
        cout << i << " ";
    }
    cout << endl;
}
