#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
    vector<vector<int>> g;
    string C;

    vector<int> dfs(int x){
        if (!memo[x].empty()){
            return memo[x];
        }
        memo[x] = {0};
        vector<int> cx(26);
        for (int y : g[x]){
            vector<int> cy = dfs(y);
            if (memo[y].size() <= 1){
                return memo[y];
            }
            for (int i=0; i<26; i++){
                cx[i] = max(cx[i], cy[i]);
            }
        }
        cx[C[x]-'a']++;
        memo[x] = cx;
        return cx;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        g.resize(n);
        for (auto& e : edges){
            g[e[0]].push_back(e[1]);
        }

        memo.resize(n);
        C = colors;
        int res = 0;
        for (int i=0; i<n; i++){
            vector<int> ci = dfs(i);
            if (ci.size() <= 1){
                return -1;
            }
            for (int j=0; j<26; j++){
                res = max(res, ci[j]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string colors = "abaca";
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
    cout << s.largestPathValue(colors, edges) << endl;
}
