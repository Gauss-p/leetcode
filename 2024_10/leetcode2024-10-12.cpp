#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums){
            mp[i]++;
        }
        int res = 0;
        for (auto&kv : mp){
            if (kv.second == 2){
                res ^= kv.first;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,1,3};
    Solution s;
    cout << s.duplicateNumbersXOR(nums) << endl;
}
