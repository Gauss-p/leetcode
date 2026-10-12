#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int modNum = 1e9+7;
        int mx = *max_element(nums.begin(), nums.end());
        int m = 32-__builtin_clz(mx);
        vector<int> cnt(m, 0);
        for (int i : nums){
            for (int j=0; j<m; j++){
                if ((i>>j)&1){
                    cnt[j]++;
                }
            }
        }

        int res = 0;
        for (int i=0; i<k; i++){
            int cur = 0;
            for (int j=0; j<m; j++){
                if (cnt[j]){
                    cur |= (1<<j);
                    cnt[j]--;
                }
            }
            res = (1ll*res+1ll*cur*cur)%modNum;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,6,5,8};
    int k = 2;
    cout << s.maxSum(nums, k) << endl;
}
