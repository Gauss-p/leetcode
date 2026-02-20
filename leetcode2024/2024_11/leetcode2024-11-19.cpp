#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    // vector<vector<int>> neibors;
    // int bfs(){
    //     int n = neibors.size();
    //     queue<int> q;
    //     q.push(0);
    //     vector<int> dist(n, -1); // dist[i]记录从0到i的最短路径长度
    //     dist[0] = 0;
    //     while (!q.empty()){
    //         int x = q.front();
    //         q.pop();
    //         for (int y : neibors[x]){
    //             if (dist[y] >= 0){
    //                 continue;
    //             }
    //             // 每次计算周围节点的最短路径长度
    //             q.push(y);
    //             dist[y] = dist[x]+1;
    //         }
    //     }
    //     return dist[n-1];
    // }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // neibors.resize(n);
        // for (int i=0; i<n-1; i++){
        //     // 这里neibors[i]记录从节点i出发可以转移到哪些节点
        //     neibors[i].push_back(i+1);
        // }
        // vector<int> res;
        // for (auto& q : queries){
        //     neibors[q[0]].push_back(q[1]); // 每次加入新边然后判断
        //     res.push_back(bfs());
        // }
        // return res;
        // ------------------------------------------------------------------------
        // 以下是动态规划
        vector<vector<int>> neibors(n); // neibors[i]记录节点i可以由哪些节点转移过来
        for (int i=1; i<n; i++){
            neibors[i].push_back(i-1);
        }
        vector<int> dp(n, 0); // 定义dp[i]表示从0到i的最短路径长度
        for (int i=0; i<n; i++){
            dp[i] = i; // 最开始0到节点i的最短路径长度都是i
        }
        vector<int> res;
        for (auto &q : queries){
            neibors[q[1]].push_back(q[0]); // 每次都加入一条边然后再计算
            for (int i=2; i<n; i++){
                for (int j : neibors[i]){
                    dp[i] = min(dp[i], dp[j]+1);
                    // 因为节点i可以由节点j移动过来，所以到i的路径长就是到j的路径长加1
                }
            }
            res.push_back(dp[n-1]); // 记录答案
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};
    vector<int> res = s.shortestDistanceAfterQueries(n, queries);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
