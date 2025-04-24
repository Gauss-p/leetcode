#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int m = set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> cnt;
        int res = 0;
        int r = 0;
        for (int l=0; l<n; l++){
            while (r<n && cnt.size()<m){
                cnt[nums[r]]++;
                r++;
            }
            if (cnt.size() == m){
                res += n-r+1;
            }
            cnt[nums[l]]--;
            if (cnt[nums[l]] == 0){
                cnt.erase(nums[l]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,1,2,2};
    cout << s.countCompleteSubarrays(nums) << endl;
}
