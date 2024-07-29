#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    vector<vector<int>> g;
public:
    Graph(int n, vector<vector<int>>& edges) {
        // 因为g需要被设置为全局变量,所以在最开始并不知道该定义多大
        // 以下是重新定义g大小的代码
        g.resize(n);
        for (int i=0; i<n; i++) g[i].resize(n, INT_MAX/2);
        for (auto e : edges){
            g[e[0]][e[1]] = e[2];
        }
    }
    
    void addEdge(vector<int> edge) {
        // 因为是有向的,所以只需设置一个值
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        int n = g.size();
        // 定义dis[i]表示从i到起点node1的最短距离,visited[i]表示i是否被访问过
        vector<int> dis(n, INT_MAX/2), visited(n);
        dis[node1] = 0; // 从自己到自己,距离为0
        while (true){
            int x = -1; // 定义x为当前节点
            for (int i=0; i<n; i++){
                // 由内向外不断将x设置为最短距离
                if (!visited[i] && (x < 0 || dis[i] < dis[x])){
                    x = i;
                }
            }
            // 如果x等于-1,说明循环不起作用,那么说明路径就此断开,无法到达
            // 如果dis[x]等于INT_MAX/2,说明没有节点可以到达node2,返回-1
            if (x == -1 || dis[x] == INT_MAX/2){
                return -1;
            }
            // 如果x已经到达node2,那么返回dis[x],即为node2到node1的最短路径长
            if (x == node2){
                return dis[x];
            }
            // 标记x已经访问过
            visited[x] = true;
            for (int y=0; y<n; y++){
                // 更新每一个节点到node1的最短路径
                // 即为y到node1最短路径长,和x到node1最短路径长加上x,y之间的距离中的最小值
                dis[y] = min(dis[y], dis[x]+g[x][y]);
            }
        }
    }
};

int main(){
    vector<vector<int>> graph = {{0,2,5},{0,1,2},{1,2,1},{3,0,3}};
    int n = 4;
    Graph s(n, graph);
    cout << s.shortestPath(3, 2) << " ";
    cout << s.shortestPath(0, 3) << " ";
    vector<int> edge = {1, 3, 4};
    s.addEdge(edge);
    cout << s.shortestPath(0, 3) << endl;
}
