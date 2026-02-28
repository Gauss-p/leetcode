#include <iostream>
#include <vector>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<int> belong;
    vector<vector<int>> g;
    priority_queue<int, vector<int>, greater<int>> h;
    vector<priority_queue<int, vector<int>, greater<int>>> heaps;

    void dfs(int x){
        belong[x] = heaps.size();
        h.push(x);
        for (auto& y : g[x]){
            if (belong[y] < 0){
                dfs(y);
            }
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        g.resize(c+1);
        for (auto& c : connections){
            int x = c[0], y = c[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        belong.resize(c+1, -1);
        for (int i=1; i<=c; i++){
            if (belong[i] >= 0){
                continue;
            }
            h = priority_queue<int, vector<int>, greater<int>>();
            dfs(i);
            heaps.push_back(h);
        }

        vector<bool> offLine(c+1, false);
        vector<int> res;
        for (auto& q : queries){
            int op = q[0], x = q[1];
            if (op == 2){
                offLine[x] = true;
                continue;
            }
            if (!offLine[x]){
                res.push_back(x);
                continue;
            }
            priority_queue<int, vector<int>, greater<int>>& h = heaps[belong[x]];
            while (!h.empty() && offLine[h.top()]){
                h.pop();
            }
            res.push_back(h.empty() ? -1 : h.top());
        }
        return res;
    }
};

int main(){
    Solution s;
    int c = 5;
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};
    vector<int> res = s.processQueries(c, connections, queries);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
