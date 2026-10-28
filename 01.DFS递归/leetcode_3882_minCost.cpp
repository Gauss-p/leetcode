#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    // 定义dfs函数，每次传入的时候同时传入当前从(0,0)到该点选择经过的路径上所有值的异或和，这样，在每次到达右下角的时候就可以用全局变量保存下最小异或值
    int m, n;
    int res;
    vector<vector<vector<int>>> memo;
    vector<vector<int>> Grid;
    void dfs(int i, int j, int cur){
        if (i == m-1 && j == n-1){
            res = min(res, cur);
            return;
        }
        if (memo[i][j][cur] == 1){
            return;
        }
        memo[i][j][cur] = 1;
        if (i < m-1){
            dfs(i+1, j, cur^Grid[i+1][j]);
        }
        if (j < n-1){
            dfs(i, j+1, cur^Grid[i][j+1]);
        }
    }
public:
    int minCost(vector<vector<int>>& grid) {
        res = INT_MAX;
        m = grid.size();
        n = grid[0].size();
        Grid = grid;
        int mx = 0;
        for (auto& r : grid){
            for (auto& x : r){
                mx |= x;
            }
        }
        memo.resize(m, vector<vector<int>>(n, vector<int>(mx+1, 0)));
        dfs(0, 0, grid[0][0]);
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2},{3,4}};
    cout << s.minCost(grid) << endl;
}
