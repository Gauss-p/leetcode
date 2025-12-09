#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int modNum = 1e9+7;
        unordered_map<int, int> pre, suf;
        for (int& i : nums){
            suf[i]++;
        }

        int res = 0;
        for (int& i : nums){
            suf[i] -= 1;
            res = (res+1ll*pre[i*2]*suf[i*2]%modNum)%modNum;
            pre[i] += 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {6,3,6};
    cout << s.specialTriplets(nums) << endl;
}
