#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        // 用dfs，从0开始搜索，只要还能往后走就往后走，否则返回
        // 每一次经过0，都取一次答案的最大值即可
        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto e : edges){
            g[e[0]].push_back(make_pair(e[1], e[2]));
            g[e[1]].push_back(make_pair(e[0], e[2]));
        }
        int res = 0;
        vector<int> visited(n);
        visited[0] = 1;
        function<void(int, int, int)> dfs = [&](int x, int val, int time){
            if (x == 0) res = max(res, val);
            for (auto [y, t] : g[x]){
                if (time+t <= maxTime){
                    if (visited[y] == 0){
                        visited[y] = 1;
                        dfs(y, val+values[y], time+t);
                        visited[y] = 0;
                    }
                    else{
                        dfs(y, val, time+t);
                    }
                }
            }
        };
        dfs(0, values[0], 0);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> values = {0, 32, 10, 43};
    vector<vector<int>> edges = {{0,1,10},{1,2,15},{0,3,10}};
    int maxTime = 49;
    cout << s.maximalPathQuality(values, edges, maxTime) << endl;
}
