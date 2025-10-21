#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> diff;
        unordered_map<int, int> cnt;
        for (int &x : nums){
            diff[x] += 0;
            diff[x-k]++;
            diff[x+k+1]--;
            cnt[x]++;
        }

        int res = 0, sumDiff = 0;
        for (auto& kv : diff){
            sumDiff += kv.second;
            res = max(res, min(sumDiff, numOperations+cnt[kv.first]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,11,20,20};
    int k = 5, numOperations = 1;
    cout << s.maxFrequency(nums, k, numOperations) << endl;
}
