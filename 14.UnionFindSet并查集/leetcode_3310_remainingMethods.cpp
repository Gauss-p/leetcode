#include <iostream>
#include <vector>
using namespace std;

class UFS{
private:
    vector<int> pa;
public:
    UFS(int n){
        for (int i=0; i<n; i++){
            pa.push_back(i);
        }
    }

    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        pa[py] = px;
    }
};

class Solution {
private:
    vector<vector<int>> g;
    vector<int> visited;
    int bad;
    void dfs(int x){
        visited[x] = 1;
        bad++;
        for (auto& y : g[x]){
            if (visited[y] == 0){
                dfs(y);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        g.resize(n);
        UFS ufs(n);
        for (auto& i : invocations){
            int a = i[0], b = i[1];
            g[a].push_back(b);
            ufs.merge(a, b);
        }

        visited.resize(n, 0);
        bad = 0;
        dfs(k);

        int target = ufs.find(k);
        int tot = 0;
        vector<int> others;
        vector<int> allNodes;
        for (int i=0; i<n; i++){
            allNodes.push_back(i);
            if (ufs.find(i) == target){
                tot++;
            }
            else{
                others.push_back(i);
            }
        }

        if (bad < tot){
            return allNodes;
        }
        return others;
    }
};

int main(){
    Solution s;
    int n = 4, k = 1;
    vector<vector<int>> invocations = {{1,2},{0,1},{3,2}};
    vector<int> res = s.remainingMethods(n, k, invocations);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
