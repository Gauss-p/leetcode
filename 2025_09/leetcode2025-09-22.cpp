#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& i : nums){
            mp[i]++;
        }
        int mx = 0, cnt = 0;
        for (auto&kv : mp){
            if (kv.second > mx){
                mx = kv.second;
                cnt = 1;
            }
            else if (kv.second == mx){
                cnt++;
            }
        }
        return cnt*mx;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,3,1,4};
    cout << s.maxFrequencyElements(nums) << endl;
}
