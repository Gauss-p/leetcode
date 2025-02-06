#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<int> vis, tmp;
    set<vector<int>> res;
    vector<int> Nums;
    int n;

    void dfs(int i){
        if (tmp.size()==n){
            res.insert(tmp);
            return;
        }
        for (int j=0; j<n; j++){
            if (vis[j] == 0){
                vis[j] = 1;
                tmp.push_back(Nums[j]);
                dfs(j);
                tmp.pop_back();
                vis[j] = 0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vis.resize(n, 0);
        Nums = nums;
        dfs(-1);
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = s.permuteUnique(nums);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
