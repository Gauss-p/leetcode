#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <numeric>
using namespace std;

const int mx = 101;
vector<vector<int>> factors(mx);
auto init = []{
    for (int i=1; i<mx; i++){
        for (int j=i; j<mx; j+=i){
            factors[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> cnt;
        for (int j=0; j<n; j++){
            if (j && nums[j]==nums[0]){
                res++;
            }
            int k2 = k/gcd(k, j);
            res += cnt[k2<<10 | nums[j]];
            for (int f : factors[j]){
                cnt[f<<10 | nums[j]]++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,2,2,2,1,3};
    int k = 2;
    cout << s.countPairs(nums, k) << endl;
}
