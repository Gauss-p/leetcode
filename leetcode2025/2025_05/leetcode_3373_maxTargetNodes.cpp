#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> cnt1, cnt2, colors;

    vector<vector<int>> build_tree(vector<vector<int>>& edges){
        int n = edges.size()+1;
        vector<vector<int>> g(n);
        for (auto& e : edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        return g;
    }

    void dfs(int x, int pa, int d, vector<vector<int>>& g, int flag){
        if (flag == 1){
            cnt1[d]++;
            colors[x] = d;
        }
        else{
            cnt2[d]++;
        }
        for (int y : g[x]){
            if (y == pa) continue;
            dfs(y, x, d^1, g, flag);
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        cnt1.resize(2, 0);
        cnt2.resize(2, 0);
        colors.resize(n);

        vector<vector<int>> g1 = build_tree(edges1), g2 = build_tree(edges2);
        dfs(0, -1, 0, g1, 1);
        dfs(0, -1, 0, g2, 2);
        int tree2max = *max_element(cnt2.begin(), cnt2.end());
        vector<int> res(n, tree2max);
        for (int i=0; i<n; i++){
            res[i] += cnt1[colors[i]];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}}, edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    vector<int> res = s.maxTargetNodes(edges1,edges2);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
