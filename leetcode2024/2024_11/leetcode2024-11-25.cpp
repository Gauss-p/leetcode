#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neibors(n+1);
        for (auto& i : times){
            neibors[i[0]].emplace_back(i[1], i[2]);
        }
        vector<int> dis(n+1, INT_MAX); // 记录从0到节点i所需的最短时间
        dis[k] = 0;
        vector<int> vis(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 大根堆，每次弹出最小的元素，即我们要找的最短路径
        pq.emplace(0, k);

        while (!pq.empty()){
            auto tmp = pq.top(); // 这个地方前面的auto千万不能加&符号，会出错，因为大根堆每次重新弹出或加入以后堆顶元素的地址不变，如果根据地址去取元素的话，有可能取到之前的元素
            pq.pop();
            int time = tmp.first, x = tmp.second;
            if (vis[x]){
                continue;
            }
            vis[x] = 1;
            for (auto& e : neibors[x]){
                int y = e.first, d = dis[x]+e.second;
                if (d < dis[y]){
                    dis[y] = d;
                    pq.emplace(dis[y], y);
                }
            }
        }

        int res = 0;
        for (int i=1; i<=n; i++){
            res = max(res, dis[i]);
        }
        // 求出从k节点到其他每一个节点的最大时间，即所求答案，如果最大值为INT_MAX，则说明有的节点没办法收到信号，返回-1
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> times = {{1,2,1},{2,3,2},{1,3,4}};
    int n = 3;
    int k = 1;
    cout << s.networkDelayTime(times, n, k) << endl;
}
