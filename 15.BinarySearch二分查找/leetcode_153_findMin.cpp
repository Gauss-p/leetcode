#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int target = nums[n-1];
        int l = 0, r = n-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid] <= target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return nums[l];
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,4,5,1,2};
    cout << s.findMin(nums) << endl;
}
