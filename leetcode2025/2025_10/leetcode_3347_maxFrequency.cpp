#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> diff;
        unordered_map<int, int> cnt;
        for (int& i : nums){
            diff[i] += 0;
            diff[i-k]++;
            diff[i+k+1]--;
            cnt[i]++;
        }

        int res = 0, sumDiff = 0;
        for (auto&kv : diff){
            sumDiff += kv.second;
            res = max(res, min(sumDiff, numOperations+cnt[kv.first]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,5};
    int k=1, numOperations=2;
    cout << s.maxFrequency(nums, k, numOperations) << endl;
}
