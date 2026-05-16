#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l<r){
            int mid = (l+r)/2;
            if (nums[mid] > nums[r]){
                l = mid+1;
            }
            else if (nums[mid] < nums[r]){
                r = mid;
            }
            else{
                r--;
            }
        }
        return nums[l];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5};
    cout << s.findMin(nums) << endl;
}
