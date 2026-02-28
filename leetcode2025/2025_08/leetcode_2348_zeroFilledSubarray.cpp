#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(1);
        long long zero = 0, res = 0;
        for (int i : nums){
            if (i != 0){
                res += (zero*(zero+1))/2;
                zero = 0;
            }
            else{
                zero++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,0,0,2,0,0,4};
    cout << s.zeroFilledSubarray(nums) << endl;
}
