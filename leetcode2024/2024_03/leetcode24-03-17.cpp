#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n, 0); // 存储每一个节点的度
        vector<vector<int>> g(n, vector<int>()); // 建图
        for (auto eg : edges){
            int x = eg[0], y = eg[1];
            degrees[x]++;
            degrees[y]++;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // 以下开始进行“剪枝”操作
        // 即由外到内一圈一圈地剪掉，直到最中间的几个节点，那么它们一定是符合规则的根节点
        // 以这些节点为根节点，树的高度可以保证最小
        // 如果一个节点偏离中心，那么以它为根节点，树高一定比(以中间那些为根的树)更高
        queue<int> q;
        for (int i=0; i<n; i++){
            if (degrees[i] == 1){
                q.emplace(i);
            }
        }
        vector<int> res = {0};
        while (!q.empty()){
            int n = q.size();
            res.clear();
            for (int i=0; i<n; i++){ 
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for (int j : g[cur]){
                    degrees[j]--;
                    if (degrees[j] == 1){
                        q.emplace(j);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    // vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    // int n = 4;
    // int ex = [[3,0],[3,1],[3,2],[3,4],[5,4]];
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    int n = 6;
    vector<int> res = s.findMinHeightTrees(n, edges);
    for (int i:res) cout << i << " ";
}
