#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i=0; i<n; i++){
            pos[nums[i]].push_back(i);
        }
        vector<long long> res(n, 0);
        for (auto& kv : pos){
            auto p = kv.second;
            int m = p.size();
            vector<long long> preSum(m+1, 0);
            for (int i=0; i<m; i++){
                preSum[i+1] = preSum[i]+p[i];
            }
            for (int i=0; i<m; i++){
                res[p[i]] += 1ll*p[i]*i-preSum[i];
                res[p[i]] += preSum[m]-preSum[i+1]-1ll*p[i]*(m-i-1);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,1,1,2};
    vector<long long> res = s.distance(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
