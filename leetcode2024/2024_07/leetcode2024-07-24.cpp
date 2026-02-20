#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; i++){
            mp[nums[i]] = 1;
        }
        for (int i=0; i<(int)moveFrom.size(); i++){
            if (moveFrom[i] != moveTo[i]){
                mp[moveTo[i]] = 1;
                mp[moveFrom[i]] = 0;
            }
        }
        vector<int> res;
        for (auto &kv : mp){
            if (kv.second != 0){
                res.push_back(kv.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int minChanges(vector<int>& nums, int k) {
        // 本题可以采用差分数组的方法来解决，首先，我们可以对每一个数对进行处理，使得左边的数字永远比右边的数字小，为了方便叙述，我们称左边的小数为p，右边的大数为q，可以发现，如果经过一次改变，那么两数的差值最大就是max(q, k-p)，其中第一项是单独改变p的最大差值，第二项则是单独改变q的最大值，令mx = max(q, k-p)，x = q-p
        // 我们发现，如果有一对数组的差值位于[0,x)或(x,mx]内，那么这对数组只需要改变一次，而对于差值大于mx的数组，就需要进行两次改变，所以用差分数组直接计算
        // 因为在差分数组中，若要对[a,b)内的所有数都加上1，只需要对差分数组的a加1，并对b减1即可，若定义dp[i]代表将所有数对的差值改变为i的最小次数，同时定义d是其差分数组，那么如果要对dp[0...x-1]加1，对dp[x+1...mx]加1，同时对dp[mx...k]加上2，只需要进行如下操作：d[0]++,d[x]--,d[x+1]++,d[mx+1]--,d[mx+1]+=2即可
        // 最终还原数组dp，求最小次数即可
        int n = nums.size();
        vector<int> d(k+2);
        for (int i=0; i<n/2; i++){
            int p = nums[i], q = nums[n-i-1];
            if (p > q){
                swap(p, q);
            }
            int x = q-p;
            int mx = max(q, k-p);
            d[0]++;
            d[x]--;
            d[x+1]++;
            d[mx+1]--;
            d[mx+1] += 2;
        }
        // for (int i=1; i<=k+1; i++){
        //     d[i] += d[i-1];
        // }
        partial_sum(d.begin(), d.end(), d.begin());
        return *min_element(d.begin(), d.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,6,7,8}, moveFrom = {1,7,2}, moveTo = {2,9,5};
    vector<int> res = s.relocateMarbles(nums, moveFrom, moveTo);
    for (auto i : res) cout << i << " ";
    cout << endl;
    nums = {1,0,1,2,4,3};
    int k = 4;
    cout << s.minChanges(nums, k) << endl;
}
