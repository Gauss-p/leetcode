#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    int calc(vector<int>& nums, int indx, int k, int x){
        unordered_map<int, int> cnt;
        for (int i=indx; i<indx+k; i++){
            cnt[nums[i]]++;
        }
        vector<pair<int, int>> items;
        for (auto& kv : cnt){
            items.push_back(make_pair(kv.second, kv.first));
        }
        sort(items.begin(), items.end());
        int res = 0;
        for (int i=max(0, (int)items.size()-x); i<items.size(); i++){
            res += items[i].first*items[i].second;
        }
        return res;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n-k+1, 0);
        for (int i=0; i<n-k+1; i++){
            ans[i] = calc(nums, i, k, x);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6, x = 2;
    vector<int> res = s.findXSum(nums, k, x);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
