#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums.size()%(i+1) == 0){
                res += nums[i]*nums[i];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.sumOfSquares(nums) << endl;
}
