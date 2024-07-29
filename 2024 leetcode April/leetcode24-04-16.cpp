#include <iostream>
#include <vector>
#include <functional>
#include <set>
using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> sizes; // 存储每个连通块的大小
        vector<vector<int>> vvi; // 存储每个连通块中被感染的电脑
        vector<vector<int>> neibor(n); // 存储每个元素的邻居
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (graph[i][j] == 1 && i != j){
                    neibor[i].push_back(j); // 如果两个不同的点之间有边，就存入neibor中
                }
            }
        }
        set<int> itl(initial.begin(), initial.end()); // 将给出的initial转化成set，方便后面查找
        // nums用来存储所有的元素，在查找每一个连通块时，都将连通块的节点从所有节点中删除
        // 这是方便我们继续找不同的连通块
        vector<int> nums;
        for (int i=0; i<n; i++){
            nums.push_back(i);
        }
        vector<int> visited(n, 0); // 这个判断是否访问过的数组是用来防止出现环路，陷入死循环的
        function<void(int, int, int)> dfs = [&](int x, int fa, int indx){
            sizes[indx]++; // 连通块的大小增加1
            if (itl.count(x)) vvi[indx].push_back(x); // 如果当前节点被感染，加入vvi[indx]中
            nums.erase(remove(nums.begin(), nums.end(), x), nums.end()); // 在nums中删除当前节点
            // cout << nums.size() << endl;
            visited[x] = 1; // 标记为已访问
            for (int y : neibor[x]){
                if (!visited[y] && y != fa){
                    // 如果没有访问过并且与父亲不相同，才可以继续访问
                    dfs(y, x, indx);
                }
            }
        };

        int indx = -1;
        // 下面的循环是用来查找所有的连通块的
        while (nums.size()){
            indx++;
            sizes.resize(indx+2);
            vvi.resize(indx+2);
            dfs(nums[0], -1, indx);
        }
        // 首先要保证整个网络中感染恶意软件的最终节点数，即M(initial)最小
        // 其次，如果有多个节点满足：删除后能够保护的节点同样多，那么就返回索引的最小值
        // 如果不存在哪一个连通块中只有一个电脑感染，那么返回已感染的电脑中索引最小的一个即可
        int max_num = 0, res = -1;
        for (int i=0; i<=indx; i++){
            if (vvi[i].size() == 1){
                if (sizes[i] > max_num){
                    max_num = sizes[i];
                    res = vvi[i][0];
                }
                if (sizes[i] == max_num){
                    res = min(res, vvi[i][0]);
                }
            }
        }
        return res == -1 ? *min_element(initial.begin(), initial.end()) : res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> initial = {0, 1};
    cout << s.minMalwareSpread(graph, initial) << endl;
}
