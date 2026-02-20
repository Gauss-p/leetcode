#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, cnt = 0;
        for (int i=0; i<pow(2, n); i++){
            int cur = 0;
            for (int j=0; j<n; j++){
                if ((i>>j)&1){
                    cur |= nums[j];
                }
            }
            if (mx < cur){
                mx = cur;
                cnt = 1;
            }
            else if (mx == cur){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1};
    cout << s.countMaxOrSubsets(nums) << endl;
}
