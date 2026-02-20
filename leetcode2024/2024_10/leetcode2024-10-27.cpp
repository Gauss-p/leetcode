#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> Union;
    int find(int x){
        return x==Union[x] ? x : find(Union[x]); // 找祖先节点
    }
    void merge(int x, int y){
        // 合并两个节点
        int paX = find(x), paY = find(y);
        if (paX != paY){
            Union[paY] = paX;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 用并查集的思路，如果发现一条边的两个端点的祖先出现相同，这就标明这里出现了一条回路，但是由于题目中要求的是在edges中最后出现的一条边，所以我们就按照edges的顺序，依次合并边两端的节点，直到发现这两个节点的祖先相同为止，直接返回当前边即可
        int n = edges.size();
        Union.resize(n+1);
        for (int i=0; i<n; i++){
            Union[i] = i;
        }
        for (auto&e : edges){
            int x = e[0], y = e[1];
            if (find(x) != find(y)){
                merge(x, y); // 合并两端的节点
            }
            else{
                // 只要出现两端节点的祖先相同，就说明出现了一个回路，且当前边是在edges中最后出现的一条
                return e;
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> res = s.findRedundantConnection(edges);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}

