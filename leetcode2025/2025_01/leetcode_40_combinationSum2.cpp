#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> newC, res;
    vector<int> vis;
    int n;
    int target;

    vector<vector<int>> dfs(int x, int score){
        if (score == target){
            vector<int> tmp;
            for (int i=0; i<n; i++){
                for (int j=0; j<vis[i]; j++){
                    tmp.push_back(newC[i][0]);
                }
            }
            return {tmp};
        }
        if (score > target || x == n){
            return {{}};
        }
        vector<vector<int>> ans;
        for (int i=0; i<=newC[x][1]; i++){
            vis[x] = i;
            vector<vector<int>> cur = dfs(x+1, score+i*newC[x][0]);
            for (auto& j : cur){
                if (j.size() > 0){
                    ans.push_back(j);
                }
            }
            vis[x] = 0;
        }
        return ans;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int tar) {
        sort(candidates.begin(), candidates.end());
        candidates.push_back(101);
        int length = 1;
        for (int i=1; i<candidates.size(); i++){
            if (candidates[i] == candidates[i-1]){
                length++;
            }
            else{
                newC.push_back({candidates[i-1], length});
                length = 1;
            }
        }

        n = newC.size();
        vis.resize(n, 0);
        target = tar;
        return dfs(0, 0);
    }
};

int main(){
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum2(candidates, target);
    for (auto i : res){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
