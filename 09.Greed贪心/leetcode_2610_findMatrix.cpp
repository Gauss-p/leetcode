#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = 0;
        for (int &i : nums){
            cnt[i]++;
            n = max(n, cnt[i]);
        }
        vector<vector<int>> res;
        for (int i=0; i<n; i++){
            vector<int> tmp;
            for (auto& kv : cnt){
                if (kv.second > 0){
                    tmp.push_back(kv.first);
                    cnt[kv.first]--;
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,4,1,2,3,1};
    vector<vector<int>> res = s.findMatrix(nums);
    for (auto&i : res){
        for (auto&j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
