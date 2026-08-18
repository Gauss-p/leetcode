#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == 1){
            unordered_map<int, int> cnt;
            for (int i : nums) cnt[i]++;
            int res = -1;
            for (auto& kv : cnt) res = kv.second==1 ? max(res, kv.first) : res;
            return res;
        }
        if (nums.size() == k){
            return *max_element(nums.begin(), nums.end());
        }

        int res = -1;
        if (count(nums.begin(), nums.end(), nums[0]) == 1){
            res = max(res, nums[0]);
        }
        if (count(nums.begin(), nums.end(), nums.back()) == 1){
            res = max(res, nums.back());
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,9,2,1,7};
    int k = 3;
    cout << s.largestInteger(nums, k) << endl;
}
