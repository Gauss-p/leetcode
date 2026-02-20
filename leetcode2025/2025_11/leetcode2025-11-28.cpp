#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> g;
    vector<int> Val;
    int res, K;

    int dfs(int x, int pa){
        int v = Val[x]%K;
        for (int& y : g[x]){
            if (y != pa){
                v = (dfs(y, x)+v)%K;
            }
        }
        res += (v==0);
        return v;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.resize(n);
        for (auto& e : edges){
            int x=e[0], y=e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        Val = values;
        res = 0;
        K = k;
        dfs(0, -1);
        return res;
    }
};

int main(){
    Solution s;
    int n = 5, k = 6;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};
    cout << s.maxKDivisibleComponents(n, edges, values, k) << endl;
}
