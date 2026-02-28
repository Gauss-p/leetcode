#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums){
            cnt[i]++;
        }
        int res = 0;
        for (auto&kv : cnt){
            int k = kv.first;
            if (cnt.count(k+1)){
                res = max(res, cnt[k]+cnt[k+1]);
            }
        }
        return res;

        // unordered_map<int, int> cnt;
        // set<int> keys;
        // for (int i : nums){
        //     keys.insert(i);
        //     cnt[i]++;
        // }
        // vector<int> v(keys.begin(), keys.end());
        // int res = 0;
        // for (int k : v){
        //     if (cnt[k+1] != 0){
        //         res = max(res, cnt[k]+cnt[k+1]);
        //     }
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << s.findLHS(nums) << endl;
}
