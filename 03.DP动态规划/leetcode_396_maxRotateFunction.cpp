#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int cur = 0, tot = 0;
        for (int i=0; i<n; i++){
            cur += nums[i]*i;
            tot += nums[i];
        }
        
        int res = cur;
        for (int i=n-1; i>=0; i--){
            cur += tot;
            cur -= n*nums[i];
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,3,2,6};
    cout << s.maxRotateFunction(nums) << endl;
}
