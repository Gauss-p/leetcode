#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int modNum = 1e9+7;
        for (auto& q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i=l; i<=r; i+=k){
                nums[i] = (1ll*nums[i]*v)%modNum;
            }
        }

        int res = 0;
        for (int i : nums){
            res = (res^i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1};
    vector<vector<int>> queries = {{0,2,1,4}};
    cout << s.xorAfterQueries(nums, queries) << endl;
}
