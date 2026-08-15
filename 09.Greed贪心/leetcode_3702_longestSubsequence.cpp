#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tot = 0;
        bool allZero = true;
        for (int i : nums){
            tot ^= i;
            allZero &= (i==0);
        }
        int n = nums.size();
        if (tot == 0){
            return allZero ? 0 : n-1;
        }
        return n;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.longestSubsequence(nums) << endl;
}
