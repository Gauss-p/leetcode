#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums;
        for (int i=0; i<n; i++){
            if (newNums.empty() || nums[i]!=newNums[newNums.size()-1]){
                newNums.push_back(nums[i]);
            }
        }
        int res = 0;
        int m = newNums.size();
        for (int i=1; i<m-1; i++){
            if ((newNums[i-1]-newNums[i])*(newNums[i+1]-newNums[i]) > 0){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,4,1,1,6,5};
    cout << s.countHillValley(nums) << endl;
}
