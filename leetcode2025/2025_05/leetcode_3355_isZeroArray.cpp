#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> newNums(n+1, 0);
        for (auto&q : queries){
            int l = q[0], r = q[1];
            newNums[l]++;
            newNums[r+1]--;
        }
        int tmp = 0;
        for (int i=0; i<n; i++){
            tmp += newNums[i];
            if (tmp < nums[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,0,1};
    vector<vector<int>> queries = {{0,2}};
    cout << s.isZeroArray(nums, queries) << endl;
}
