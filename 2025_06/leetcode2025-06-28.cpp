#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> keyVals;
        int n = nums.size();
        for (int i=0; i<n; i++){
            keyVals.emplace_back(nums[i], i);
        }
        sort(keyVals.rbegin(), keyVals.rend());
        vector<pair<int, int>> frontK;
        for (int i=0; i<k; i++){
            frontK.emplace_back(keyVals[i].second, keyVals[i].first);
        }
        sort(frontK.begin(), frontK.end());
        vector<int> res;
        for (auto&kv : frontK){
            res.push_back(kv.second);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3,3};
    int k = 2;
    vector<int> res = s.maxSubsequence(nums, k);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
