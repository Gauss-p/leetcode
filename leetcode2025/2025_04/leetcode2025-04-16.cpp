#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        long long res = 0, ok = 0, r = 0;
        for (int l=0; l<n; l++){
            while (r<n && ok<k){
                ok += cnt[nums[r]];
                cnt[nums[r]]++;
                r++;
            }
            if (ok >= k){
                res += (n-r+1);
            }
            cnt[nums[l]]--;
            ok -= cnt[nums[l]];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,4,3,2,2,4};
    int k = 2;
    cout << s.countGood(nums, k) << endl;
}
