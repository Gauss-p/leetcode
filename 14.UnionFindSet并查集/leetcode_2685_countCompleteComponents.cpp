#include <iostream>
#include <vector>
#include <unordered_map>
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
        if (px<py){
            pa[py] = px;
        }
        else{
            pa[px] = py;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UFS ufs(n);
        for (auto& e : edges){
            ufs.merge(e[0], e[1]);
        }

        unordered_map<int, long long> groups, cnt;
        for (int i=0; i<n; i++){
            groups[ufs.find(i)]++;
        }
        for (auto& e : edges){
            cnt[ufs.find(e[0])]++;
        }

        int res = 0;
        for (auto& kv : groups){
            long long cur = groups[kv.first]*(groups[kv.first]-1)/2;
            if (cur == cnt[kv.first]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    cout << s.countCompleteComponents(n, edges) << endl;
}
