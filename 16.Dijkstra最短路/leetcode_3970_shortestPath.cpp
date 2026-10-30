#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges){
            g[e[0]].emplace_back(e[1], e[2]);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, labels[0], 1});
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        dist[0][1] = 0;
        vector<vector<int>> visited(n, vector<int>(k+1, 0));
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            int d = cur[0], x = cur[1], c = cur[2], l = cur[3];
            if (visited[x][l]){
                continue;
            }
            visited[x][l] = 1;
            for (auto& nxt : g[x]){
                int y = nxt.first, w = nxt.second;
                int nl = 1;
                if (labels[y] == c){
                    nl += l;
                }
                if (nl > k){
                    continue;
                }
                if (d+w < dist[y][nl]){
                    dist[y][nl] = d+w;
                    q.push({d+w, y, labels[y], nl});
                }
            }
        }
        int res = *min_element(dist.back().begin(), dist.back().end());
        return res<INT_MAX ? res : -1;
    }
};

int main(){
    Solution s;
    int n = 3, k = 1;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{0,2,3}};
    string labels = "aab";
    cout << s.shortestPath(n, edges, labels, k) << endl;
}
