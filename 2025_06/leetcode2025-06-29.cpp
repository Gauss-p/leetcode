#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MOD_NUM = 1e9+7;
int MAX_NUM = 1e5+1;
vector<int> pow2(MAX_NUM, 1);
auto init = []{
    for (int i=1; i<MAX_NUM; i++){
        pow2[i] = (pow2[i-1]*2)%MOD_NUM;
    }
    return 0;
}();

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        int res = 0;
        int modNum = 1e9+7;
        while (l<=r){
            if (nums[l]+nums[r]<=target){
                res = (res+pow2[r-l])%modNum;
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,3,4,6,7};
    int target = 12;
    cout << s.numSubseq(nums, target) << endl;
}
