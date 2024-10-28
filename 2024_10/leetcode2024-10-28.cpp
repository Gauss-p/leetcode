#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> parent;
    void initParent(){
        // 该函数用来初始化并查集的祖先数组
        // 因为主程序中可能多次需要初始化
        int n = parent.size();
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        // 寻找节点x的祖先，并将x的所有更高层节点的祖先都置为x的祖先
        if (x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y){
        // 合并x,y节点
        x = find(x);
        y = find(y);
        if (x != y){
            parent[y] = x;
        }
    }
    bool isTheSameGrand(int x, int y){
        // 判断x,y是否拥有相同的祖先
        x = find(x);
        y = find(y);
        return x == y;
    }

    bool isTreeAfterDeleteAEdge(vector<vector<int>>& edges, int e){
        initParent();
        for (int i=0; i<edges.size(); i++){
            if (i == e){
                // 删除我们暂定的冗余连接
                continue;
            }
            int x = edges[i][0], y = edges[i][1];
            if (isTheSameGrand(x, y)){
                // 只要还有环路，就说明该冗余连接选择的不对
                return false;
            }
            Union(x, y); // 否则继续合并
        }
        return true;
    }
    vector<int> findTheEdge(vector<vector<int>>& edges){
        initParent();
        for (int i=0; i<edges.size(); i++){
            int x = edges[i][0], y = edges[i][1];
            if (isTheSameGrand(x, y)){
                // 只要发现回路，就说明这条边是我们需要的答案
                return edges[i];
            }
            Union(x, y);
        }
        return {};
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 通过观察，我们发现多出的这条边可能有两种情况，第一种是导致树中某个节点的入度变成了2，而第二种则是导致整棵树中出现了一个有向环。那么我们可以首先遍历整棵树，计算所有的点的入度，接下来再次遍历所有边，将所有终点入度为2的边加入一个列表中。在执行完以上操作后，有两种情况，第一种是该列表中正好有两条边，说明属于第一种情况，第二种则是该列表为空，这说明是第二种情况。
        // 对于第一种情况，由于我们已经找到指向入度为2的点的两条边，那么就已经锁定了答案在这两条边中，这时候我们查找一下，如果说删除第一条边后树中就没有环路，那么答案即为第一条边，否则答案就是第二条边
        // 对于第二种情况，我们只需要遍历所有边并依次加入并查集的祖先数组中，直到发现当前边的两个节点具有相同的祖先时，就说明这条边是索引最大的那条多余的连接，返回当前边即可。如果没有查到，返回空即可
        parent.resize(1001);
        int n = edges.size();
        vector<int> inDegree(1001, 0);// 计算入度
        for (int i=0; i<n; i++){
            inDegree[edges[i][1]]++;
        }
        vector<int> mightDelete; // 加入可供选择的待删除的边
        for (int i=n-1; i>=0; i--){
            if (inDegree[edges[i][1]] == 2){
                mightDelete.push_back(i);
            }
        }
        // return {};
        if (mightDelete.size()){
            if (isTreeAfterDeleteAEdge(edges, mightDelete[0])){
                // 测试删除第一条边是否可行
                return edges[mightDelete[0]];
            }
            else{
                return edges[mightDelete[1]];
            }
        }
        // return {};
        return findTheEdge(edges);
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges ={{1,2},{1,3},{2,3}};
    vector<int> res = s.findRedundantDirectedConnection(edges);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
