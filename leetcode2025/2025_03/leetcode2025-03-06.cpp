#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> cnt;
        cnt[0]++;
        long long res = 0, tmpXor = 0;
        for (int& i : nums){
            tmpXor ^= i;
            res += cnt[tmpXor];
            cnt[tmpXor]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,3,1,2,4};
    cout << s.beautifulSubarrays(nums) << endl;
}
