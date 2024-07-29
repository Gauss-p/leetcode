#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<vector<pair<int, int>>> g(n);
        // 建图，用pair<int, int>存储对应节点的编号以及这条边的权值
        for (auto &e : edges){
            int x = e[0], y = e[1];
            g[x].push_back(make_pair(y, e[2]));
            g[y].push_back(make_pair(x, e[2]));
        }
        // 定义dfs函数，计算以pa为起始点，pa->x为方向的分支上有多少个节点符合要求
        function<int(int, int, int)> dfs = [&](int x, int pa, int tmp){
            int res = 0;
            // tmp用来存储截止当前节点，之前所有边的权值之和抹除signalSpeed的值
            // 所以，如果tmp为0，就说明当前节点是合格节点
            if (tmp == 0){
                res++;
            }
            for (auto kv : g[x]){
                if (kv.first != pa){
                    // 防止掉头回去重复算
                    res += dfs(kv.first, x, (tmp+kv.second)%signalSpeed);
                }
            }
            return res;
        };
        // 接下来计算答案
        // 因为我们可以算出,从节点i开始,i->k为方向上的所有合规节点,那么就循环所有方向,计算可能的点对数目
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++){
            int tmp_sum = 0;
            for (auto &kv : g[i]){
                int cur = dfs(kv.first, i, kv.second % signalSpeed);
                ans[i] += tmp_sum*cur; // 计算点对数目
                tmp_sum += cur;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2}};
    int signalSpeed = 1;
    vector<int> res =  s.countPairsOfConnectableServers(edges, signalSpeed);
    for (auto i : res){
        cout << i << " ";
    }
}
