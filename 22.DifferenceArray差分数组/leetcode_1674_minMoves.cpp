#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit+2, 0);
        for (int i=0; i<n/2; i++){
            int a = nums[i], b = nums[n-i-1];
            
            int l = 2, r = 2*limit;
            diff[l] += 2;
            diff[r+1] -= 2;

            l = 1+min(a, b);
            r = limit+max(a,b);
            diff[l] += -1;
            diff[r+1] -= -1;

            l = a+b;
            r = a+b;
            diff[l] += -1;
            diff[r+1] -= -1;
        }

        int res = n;
        int cur = 0;
        for (int i=2; i<2*limit+1; i++){
            cur += diff[i];
            res = min(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,4,3};
    int limit = 4;
    cout << s.minMoves(nums, limit) << endl;
}
