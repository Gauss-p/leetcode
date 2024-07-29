#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n); // 用来存储每一个节点指向的节点
        vector<int> degrees(n); // 用来存储每一个节点的入度
        for (auto &e : edges){
            // 创建图表以及入度表
            int from = e[0], to = e[1];
            g[from].push_back(to);
            degrees[to]++;
        }
        // 将入度为0的所有节点加入队列，利用剪枝的方法一圈一圈地累加祖先
        queue<int> q;
        for (int i=0; i<n; i++){
            if (degrees[i] == 0){
                q.push(i);
            }
        }
        vector<unordered_set<int>> vvi(n); // 其中unordered_set用来去重
        while (q.size()){
            // 如果[fa, i]是一条存在的边，说明i的所有祖先应该是i的已知祖先加fa的已知祖先再加上fa
            int fa = q.front();
            q.pop();
            for (int i : g[fa]){
                for (int j : vvi[fa]){
                    vvi[i].insert(j); // fa的祖先是它所有孩子的祖先
                }
                vvi[i].insert(fa); // 同时fa自己也应该是它所有孩子的祖先
                degrees[i]--;
                if (degrees[i] == 0){
                    q.push(i);
                }
            }
        }
        vector<vector<int>> res(n);
        for (int i=0; i<n; i++){
            // 由于vvi[i]是已去重的祖先，所以最终结果只需要排序即可
            res[i].insert(res[i].end(), vvi[i].begin(), vvi[i].end());
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    int n = 8;
    vector<vector<int>> res = s.getAncestors(n, edges);
    for (auto &i : res){
        for (auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
