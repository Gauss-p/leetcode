#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> g;
    int ans;

    int dfs(int x, int pa){
        if (x != 0 && g[x].size() == 1){
            ans++;
            return 1;
        }
        int res = 1;
        int childTree = 0; // 子树的大小，辅助判断x是否为好节点
        bool flag = true; // 判断当前节点x是否为好节点
        for (auto y : g[x]){
            if (y == pa){
                continue;
            }
            int tmp = dfs(y, x);
            res += tmp; // 统计以x为根节点的子树的总结点数
            if (childTree == 0){
                childTree = tmp;
            }
            else{
                if (tmp != childTree){
                    flag = false;
                }
            }
        }
        if (flag){
            ans++;
            // 统计答案
        }
        return res;
    };

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> cnt(n);
        g.resize(n);
        for (auto &e : edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        ans = 0;
        dfs(0, -1);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    cout << s.countGoodNodes(edges) << endl;
}
