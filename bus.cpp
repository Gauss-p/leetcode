#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Node{
	int u, t, d;
	bool operator<(const Node &newNode) const{
		return d>newNode.d;
	}
};

vector<vector<pair<int, int>>> Graph;
vector<vector<int>> G_d;
vector<vector<int>> G_vis;

int main(){
	freopen("bus2.in", "r", stdin);
	// freopen("bus1.out", "w", stdout);
    // 用稍微修改的dijkstra算法，就可以解决本问题，算法思路如下：首先定义从节点0到其余的每一个节点的最短路径，当然，0本身到自己的最短路径就是0了，接下来，将0节点放入一个队列中，利用BFS算法不断遍历，更新队首元素周围所有邻居的最短路径，然后，如果发现有一个邻居被更新了最短的路径，就将该邻居加入优先级队列中，这就导致一种情况，就是有可能一个邻居被压入优先级队列多次，这时候我们创建一个visited列表来记录节点是否被访问过即可，跳过所有被访问过的节点，最终可以更新到最后一个节点，这时候返回最后一个节点即可
    // 但是对于该题目，有一点需要注意，就是每一条路径有一个最晚时间限制，如果发现没办法通过这条路，那么就延迟到达出口的时间，并以k的倍数往后延长即可

	int nodeNum, pathNum, kk;
	cin >> nodeNum >> pathNum >> kk;
	Graph.resize(nodeNum+1);// 建图
	for (int i=0; i<pathNum; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Graph[u].emplace_back(v, w);
	}
	G_d.resize(nodeNum+1, vector<int>(kk, INT_MAX));
	G_vis.resize(nodeNum+1, vector<int>(kk, 0));
	G_d[1][0] = 0;
	priority_queue<Node> q;
	q.push({1, 0, G_d[1][0]});

	while (!q.empty()){// BFS寻找最短路径
		int u = q.top().u, t = q.top().t;
		q.pop();
		if (G_vis[u][t]){
            // 跳过以访问的节点
			continue;
		}
		G_vis[u][t] = 1;
		// for (auto [uc, wc] : Graph[u]){
		for (int indx = 0; indx<Graph[u].size(); indx++){
			int uc = Graph[u][indx].first, wc = Graph[u][indx].second;
			int curT = G_d[u][t], j = (t+1)%kk;
			if (curT < wc){
                // 延后到达出口的时间
				curT += (wc-curT+kk-1)/kk*kk;
			}
			if (G_d[uc][j] > curT+1){
				G_d[uc][j] = curT+1;
				q.push({uc, j, curT+1});
			}
		}
	}
	if (G_d[nodeNum][0] == INT_MAX){
		cout << -1 << endl;
	}
	else{
		cout << G_d[nodeNum][0] << endl;
	}

	fclose(stdin);
	// fclose(stdout);
	return 0;
}

