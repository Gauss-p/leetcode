#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid] <= nums.back()){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        int indx = r;
        l = 0;
        r = nums.size()-1;
        if (target <= nums.back()){
            l = indx+1;
        }
        else{
            r = indx;
        }
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return (l<nums.size() && nums[l]==target) ? l : -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << s.search(nums, target) << endl;
}
