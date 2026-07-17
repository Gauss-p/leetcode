#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = 0;
        unordered_map<int, int> cnt;
        for (int i : nums){
            mx = max(mx, i);
            cnt[i]++;
        }

        vector<long long> cntGcd(mx+1, 0);
        for (int i=mx; i>=1; i--){
            long long tot = 0, minus = 0;
            for (int j=i; j<=mx; j+=i){
                tot += cnt[j];
                minus += cntGcd[j];
            }
            cntGcd[i] = tot*(tot-1)/2-minus;
        }

        vector<long long> preSum(mx+1, 0);
        for (int i=1; i<=mx; i++){
            preSum[i] = preSum[i-1]+cntGcd[i];
        }

        vector<int> res;
        for (long long q : queries){
            res.push_back(lower_bound(preSum.begin(), preSum.end(), q+1)-preSum.begin());
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,4};
    vector<long long> queries = {0,2,2};
    vector<int> res = s.gcdValues(nums, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
