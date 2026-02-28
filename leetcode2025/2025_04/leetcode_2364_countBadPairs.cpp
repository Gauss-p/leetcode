#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        long long res = 1ll*n*(n-1)/2;
        for (int i=0; i<n; i++){
            res -= cnt[nums[i]-i];
            cnt[nums[i]-i]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,1,3,3};
    cout << s.countBadPairs(nums) << endl;
}
