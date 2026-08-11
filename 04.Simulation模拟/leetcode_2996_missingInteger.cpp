#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) cnt[i]++;
        nums.push_back(-1);
        int i = 1, mx = nums[0];
        while (nums[i-1]+1 == nums[i]){
            mx += nums[i];
            i++;
        }

        while (cnt.count(mx)){
            mx++;
        }
        return mx;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,2,5};
    cout << s.missingInteger(nums) << endl;
}
