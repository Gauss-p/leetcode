#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    vector<vector<int>> g;
public:
    Graph(int n, vector<vector<int>>& edges) {
        // ��Ϊg��Ҫ������Ϊȫ�ֱ���,�������ʼ����֪���ö�����
        // ���������¶���g��С�Ĵ���
        g.resize(n);
        for (int i=0; i<n; i++) g[i].resize(n, INT_MAX/2);
        for (auto e : edges){
            g[e[0]][e[1]] = e[2];
        }
    }
    
    void addEdge(vector<int> edge) {
        // ��Ϊ�������,����ֻ������һ��ֵ
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        int n = g.size();
        // ����dis[i]��ʾ��i�����node1����̾���,visited[i]��ʾi�Ƿ񱻷��ʹ�
        vector<int> dis(n, INT_MAX/2), visited(n);
        dis[node1] = 0; // ���Լ����Լ�,����Ϊ0
        while (true){
            int x = -1; // ����xΪ��ǰ�ڵ�
            for (int i=0; i<n; i++){
                // �������ⲻ�Ͻ�x����Ϊ��̾���
                if (!visited[i] && (x < 0 || dis[i] < dis[x])){
                    x = i;
                }
            }
            // ���x����-1,˵��ѭ����������,��ô˵��·���ʹ˶Ͽ�,�޷�����
            // ���dis[x]����INT_MAX/2,˵��û�нڵ���Ե���node2,����-1
            if (x == -1 || dis[x] == INT_MAX/2){
                return -1;
            }
            // ���x�Ѿ�����node2,��ô����dis[x],��Ϊnode2��node1�����·����
            if (x == node2){
                return dis[x];
            }
            // ���x�Ѿ����ʹ�
            visited[x] = true;
            for (int y=0; y<n; y++){
                // ����ÿһ���ڵ㵽node1�����·��
                // ��Ϊy��node1���·����,��x��node1���·��������x,y֮��ľ����е���Сֵ
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
