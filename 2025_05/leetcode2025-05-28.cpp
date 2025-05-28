#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> build_tree(vector<vector<int>>& edges){ // 建图函数
        int n = edges.size()+1;
        vector<vector<int>> g(n);
        for (auto& e : edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        return g;
    }

    int dfs(int x, int pa, int depth, int K, vector<vector<int>>& g){
        if (depth > K){
            // 保证深度不超过路径长度限制
            return 0;
        }
        int ans = 1; // 保存当前节点x
        for (int y : g[x]){
            if (y == pa){
                continue;
            }
            ans += dfs(y, x, depth+1, K, g);
        }
        return ans;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // 也可以使用dfs的方法，每次传入一个图，给出一个节点，那么直接用深度优先搜索找出所有深度小于等于给出的路径长度限制的节点个数即可。即dfs(x, pa, depth, k, g)的返回值就是在g中从x出发所有深度小于等于k的节点个数
        // 首先对于edges2中的每一个点我们都计算一次，求出从第二个图中的某个节点出发，深度小于等于k-1的最大节点个数，那么对于edges1中的每一个点只需计算出深度小于等于k的最大节点个数，加上edges2中计算出的最大值，即可得到答案
        if (k == 0){
            return vector<int>(edges1.size()+1, 1);
        }
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>> g1 = build_tree(edges1), g2 = build_tree(edges2);
        int tree2max = 0; // 记录edges2中的最大合法节点值
        for (int i=0; i<m; i++){
            tree2max = max(tree2max, dfs(i, -1, 0, k-1, g2));
        }

        vector<int> res(n, 1);
        for (int i=0; i<n; i++){
            // 因为已经有edges2中最大合法节点值，那每一次都将那个节点连接到edges1中的第i个节点即可
            // 所以只需计算出edges1中从i出发深度小于等于k的节点数量相加即可
            res[i] = dfs(i, -1, 0, k, g1)+tree2max;
        }
        return res;
    }
};

// class Solution {
// private:
//     vector<int> generate_dis(vector<vector<int>>& edges, int k){
//         int n = edges.size()+1;
//         vector<vector<int>> g(n);
//         for (auto& e : edges){
//             int a = e[0], b = e[1];
//             g[a].push_back(b);
//             g[b].push_back(a);
//         }

//         vector<int> res(n);
//         for (int i=0; i<n; i++){
//             res[i] = bfs(g, i, k);
//         }
//         return res;
//     }

//     int bfs(vector<vector<int>>& g, int i, int k){
//         int n = g.size();
//         queue<int> q;
//         q.push(i);
//         int depth = 0;
//         int ans = 0;
//         vector<int> visited(n, 0);
//         while (q.size() && depth<k){
//             depth += 1;
//             queue<int> cur;
//             while (!q.empty()){
//                 int x = q.front();
//                 q.pop();
//                 visited[x] = 1;
//                 for (int y : g[x]){
//                     if (visited[y]){
//                         continue;
//                     }
//                     cur.push(y);
//                     ans += 1;
//                 }
//             }
//             q = move(cur);
//         }
//         return ans;
//     }

// public:
//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
//         int n = edges1.size()+1;
//         if (k == 0){
//             return vector<int>(n, 1);
//         }

//         vector<int> d1 = generate_dis(edges1, k), d2 = generate_dis(edges2, k-1);
//         int tree2max = 0;
//         for (int i : d2){
//             tree2max = max(tree2max, i);
//         }
//         tree2max++;
//         vector<int> res(n);
//         for (int i=0; i<n; i++){
//             res[i] = d1[i]+1+tree2max;
//         }
//         return res;
//     }
// };

int main(){
    Solution s;
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}}, edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    vector<int> res = s.maxTargetNodes(edges1, edges2, k);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
