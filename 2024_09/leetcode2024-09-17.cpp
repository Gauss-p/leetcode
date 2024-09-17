#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target){
            // 处理特殊情况
            return 0;
        }
        int n = routes.size();
        vector<vector<int>> edges(n, vector<int>(n, 0)); // edges[i][j]表示第i辆车是否能转到第j辆车
        unordered_map<int, vector<int>> stop_buses; // 每一个站点都记录哪些车经过该站点
        for (int i=0; i<n; i++){
            for (int site : routes[i]){
                // 循环第i辆车经过的站点，这样就可以直接统计两个数组，其中edges[i]用来记录可以从第i辆车转到哪些车，那么就可以直接遍历第site个站点还有哪些车通过，直接记录即可
                // 同时对于stop_buses[site]，直接添加i，就可以记录下经过site站点的车辆
                for (int j : stop_buses[site]){
                    edges[i][j] = true;
                    edges[j][i] = true;
                }
                stop_buses[site].push_back(i);
            }
        }
        vector<int> dis(n, -1); // 坐上每一辆公交车需要换车的次数
        queue<int> q;
        for (auto i : stop_buses[source]){
            // 题目要求我们从source站开始上车，所以可以将经过source站的所有车的换车次数记为1，同时将这些车都加入q，方便之后的BFS
            dis[i] = 1;
            q.push(i);
        }
        while (!q.empty()){
            int tmp_bus = q.front();
            q.pop();
            for (int next=0; next<n; next++){
                if (edges[tmp_bus][next] && dis[next] == -1){
                    // 如果tmp_bus可以转到next，并且第next辆车之前并没有上过，就说明上第next辆车的换车次数就等于上第tmp_bus辆车的换车次数加1
                    dis[next] = dis[tmp_bus]+1;
                    q.push(next);
                }
            }
        }
        int res = INT_MAX;
        for (int i : stop_buses[target]){
            // 最后统计到达target站的所有车中换车次数最少的是多少即可
            if (dis[i] != -1){
                res = min(res, dis[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1, target = 6;
    cout << s.numBusesToDestination(routes, source, target) << endl;
}
