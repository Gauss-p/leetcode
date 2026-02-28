#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i=n-1; i>=2; i--){
            int left = 0, right = i-1;
            while (left < right){
                if (nums[left]+nums[right] > nums[i]){
                    res += (right-left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,2,3,4};
    cout << s.triangleNumber(nums) << endl;
}
