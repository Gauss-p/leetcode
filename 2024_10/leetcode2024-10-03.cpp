#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges){
            int x = e[0], y = e[1], c = e[2];
            g[x].emplace_back(y, c);
            g[y].emplace_back(x, c);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({passingFees[0], 0, 0}); // pq中每一个元素分别表示：到达节点x的花费，x，0到x的时间
        vector<int> timeCost(n, INT_MAX); // timeCost[i]记录从0到达i的最小时间
        timeCost[0] = 0;
        while (pq.size()){
            vector<int> tmp = pq.top();
            pq.pop();
            // 每一次取出最小花费的节点，使用dijkstra算法，取出最短的路径
            int fee = tmp[0], pos = tmp[1], curTime = tmp[2];
            if (pos == n-1){
                return fee;
            }
            for (auto& [y, tmpTime] : g[pos]){
                // 从pos继续走到y
                int newTime = curTime + tmpTime;
                if (newTime > maxTime || newTime >= timeCost[y]){
                    // 如果到达y的时间大于最大时间，或者到达y的时间已经比y之前记录下来的时间大了，就没有必要计算
                    continue;
                }
                timeCost[y] = newTime;
                pq.push({fee+passingFees[y], y, newTime});
            }
        }
        return -1;
        // ---------------------------------------------
        // int nodeNum = passingFees.size();
        // vector<vector<int>> dp(maxTime+1, vector<int> (nodeNum, INT_MAX/2));
        // dp[0][0] = passingFees[0];
        // for (int t=1; t<=maxTime; t++){
        //     for (auto& e : edges){
        //         int i = e[0], j = e[1], c = e[2];
        //         if (c <= t){
        //             dp[t][i] = min(dp[t][i], dp[t-c][j]+passingFees[i]);
        //             dp[t][j] = min(dp[t][j], dp[t-c][i]+passingFees[j]);
        //         }
        //     }
        // }
        // int res = INT_MAX/2;
        // for (int i=1; i<=maxTime; i++){
        //     res = min(res, dp[i][nodeNum-1]);
        // }
        // return res==INT_MAX/2 ? -1 : res;
    }
};

int main(){
    Solution s;
    int maxTime = 29;
    vector<vector<int>> edges = {{0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}};
    vector<int> passingFees = {5,1,2,20,20,3};
    cout << s.minCost(maxTime, edges, passingFees) << endl;
}
