#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
private:
    int n;
    long long K;
    vector<vector<vector<int>>> g;
    bool check(int mid){
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> q;
        q.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> visited(n, 0);
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            long long d = cur[0], x = cur[1];
            if (visited[x]){
                continue;
            }
            visited[x] = 1;
            for (auto& nxt : g[x]){
                long long y = nxt[0], c = nxt[1];
                if (c < mid){
                    continue;
                }
                if (d+c < dist[y]){
                    dist[y] = d+c;
                    q.push({dist[y], y});
                }
            }
        }
        return dist[n-1] <= K;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        K = k;
        int l = INT_MAX, r = 0;
        g.resize(n);
        for (auto& e : edges){
            l = min(l, e[2]);
            r = max(r, e[2]);
            if (online[e[0]] && online[e[1]]){
                g[e[0]].push_back({e[1], e[2]});
            }
        }
        
        if (!check(l)){
            return -1;
        }

        while (l<=r){
            int mid = (l+r)/2;
            if (check(mid)){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1,5},{1,3,10},{0,2,3},{2,3,4}};
    vector<bool> online = {true,true,true,true};
    int k = 10;
    cout << s.findMaxPathScore(edges, online, k) << endl;
}
