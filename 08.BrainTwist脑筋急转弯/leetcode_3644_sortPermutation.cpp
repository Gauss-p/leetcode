#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != i){
                res &= (i&nums[i]);
            }
        }
        return res==-1 ? 0 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,3,2,1};
    cout << s.sortPermutation(nums) << endl;
}
