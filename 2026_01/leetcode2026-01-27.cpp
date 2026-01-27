#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        for (int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w*2);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(make_pair(0, 0));
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        vector<int> visited(n, 0);
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            int d = cur.first, x = cur.second;
            if (visited[x]){
                continue;
            }
            visited[x] = 1;
            for (auto& nxt : g[x]){
                int dy = d+nxt.second;
                if (dy < dist[nxt.first]){
                    dist[nxt.first] = dy;
                    q.push(make_pair(dy, nxt.first));
                }
            }
        }
        return dist[n-1]==INT_MAX ? -1 : dist[n-1];
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};
    cout << s.minCost(n, edges) << endl;
}
