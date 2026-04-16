#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        for (int i=0; i<n; i++){
            pos[nums[i]].push_back(i-n);
            pos[nums[i]].push_back(i);
            pos[nums[i]].push_back(i+n);
        }
        for (auto& kv : pos){
            sort(pos[kv.first].begin(), pos[kv.first].end());
        }
        vector<int> res(queries.size(), -1);
        for (int i=0; i<queries.size(); i++){
            int cur = queries[i], x = nums[cur];
            if (pos[x].size() == 3){
                continue;
            }
            int indx = lower_bound(pos[x].begin(), pos[x].end(), cur)-pos[x].begin();
            res[i] = min(cur-pos[x][indx-1], pos[x][indx+1]-cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};
    vector<int> res = s.solveQueries(nums, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
