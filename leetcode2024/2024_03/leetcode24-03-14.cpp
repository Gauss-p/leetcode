#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        long long tmp = nums[n-1];
        for (int i=n-2; i>=0; i--){
            if (nums[i] <= tmp){
                tmp += nums[i];
            }
            else{
                res = max(res, tmp);
                tmp = nums[i];
            }
        }
        res = max(res, tmp);
        return res;
    }
};

int main(){
    Solution s;
    // vector<int> nums = {2,3,7,9,3};
    vector<int> nums = {5,3,3};
    cout << s.maxArrayValue(nums) << endl;
}
